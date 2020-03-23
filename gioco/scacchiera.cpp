#include "scacchiera.h"

Scacchiera::Scacchiera(int _width,int _height)
    : width(_width), height(_height)
{   
    if(width < 2 || height < 2)
        throw ErroreScacchiera(BOARD_TOO_SMALL);

    scacchiera = new Pedina*[width*height];
    for(int i=0; i < width*height; ++i)
        scacchiera[i] = nullptr;
}

Pedina*& Scacchiera::elementAt(int x,int y) const
{
    return *(scacchiera+y*width+x);
}

bool Scacchiera::insert(const Pedina& toInsert, int x, int y)
{
    if(isFree(x, y))
    {
        elementAt(x,y) = toInsert.clone();
        return true;
    }
    return false;
}

bool Scacchiera::move(int x1, int y1, int x2, int y2) // TODO: RIVEDERE IMPLEMENTAZIONE DOPO DEFINIZIONE DI GIOCO
{
    if(isFree(x2,y2))
    {
        elementAt(x2,y2)=elementAt(x1,y1);
        elementAt(x1,y1)=nullptr;
        return true;
    }
    return false;
}

void Scacchiera::moveAndEat(int x1, int y1, int x2, int y2)
{
    remove(x2,y2);
    move(x1,y1,x2,y2);
}

void Scacchiera::remove(int x,int y)
{
    delete elementAt(x,y);
}

bool Scacchiera::isFree(int x, int y) const
{
    return elementAt(x,y)==nullptr;
}

void Scacchiera::destroy()
{
    for(int i=0;i<width*height;++i)
        delete scacchiera[i];
}

void Scacchiera::copy(const Scacchiera& s)
{
    if(width != s.width || height != s.height)
        throw ErroreScacchiera(ERR_CPY);
    scacchiera=new Pedina*[width*height];
    for(int i=0; i < width*height; ++i)
        scacchiera[i]=s.scacchiera[i];
}

Scacchiera::Scacchiera(const Scacchiera& s) : width(s.width), height(s.height)
{
    // sappiamo per certo che non verrà sollevata eccezione perché le dimensioni sono uguali
    copy(s);
}

Scacchiera::~Scacchiera()
{
    destroy();
    delete[] scacchiera;
}

Scacchiera& Scacchiera::operator=(const Scacchiera& s)
{
    if(this != &s)
    {
        destroy();
        copy(s);
    }
    return *this;
}

int Scacchiera::getWidth() const { return width; }
int Scacchiera::getHeight() const { return height; }

Scacchiera::iterator Scacchiera::begin() const
{
    return iterator(scacchiera);
}
Scacchiera::iterator Scacchiera::end() const
{
    return iterator(scacchiera+width*height);
}

// CLASSE ITERATOR
Scacchiera::iterator::iterator(Pedina** _p): p(_p){}
Scacchiera::iterator& Scacchiera::iterator::operator++()
{
    ++p;
    return *this;
}
Scacchiera::iterator Scacchiera::iterator::operator++(int)
{
    Scacchiera::iterator it(*this);
    ++p;
    return it;
}
Scacchiera::iterator& Scacchiera::iterator::operator--()
{
    --p;
    return *this;
}
Scacchiera::iterator Scacchiera::iterator::operator--(int)
{
    Scacchiera::iterator it(*this);
    --p;
    return it;
}
Pedina*& Scacchiera::iterator::operator*() { return *p; }
Pedina** Scacchiera::iterator::operator->() { return p; }

Pedina*& Scacchiera::iterator::operator[](int i) { return *(p+i); }

// CLASS CONST_ITERATOR
Scacchiera::const_iterator::const_iterator(Pedina** const _p): p(_p) {}
Scacchiera::const_iterator::const_iterator(const iterator& it): p(it.p) {}
Scacchiera::const_iterator& Scacchiera::const_iterator::operator++()
{
    ++p;
    return *this;
}
Scacchiera::const_iterator Scacchiera::const_iterator::operator++(int)
{
    Scacchiera::const_iterator cit(*this);
    ++p;
    return cit;
}
Scacchiera::const_iterator& Scacchiera::const_iterator::operator--()
{
    --p;
    return *this;
}
Scacchiera::const_iterator Scacchiera::const_iterator::operator--(int)
{
    Scacchiera::const_iterator cit(*this);
    --p;
    return cit;
}
const Pedina*& Scacchiera::const_iterator::operator*() { return *p; }
const Pedina** Scacchiera::const_iterator::operator->() { return p; }
const Pedina*& Scacchiera::const_iterator::operator[](int i) { return *(p+i); }