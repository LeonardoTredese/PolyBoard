#include "scacchiera.h"

Scacchiera::Scacchiera(int _width,int _height): scacchiera(new Pedina*[width*height])
{   
    if(_width < 2 || height < 2)
        throw ErroreScacchiera(BOARD_TOO_SMALL);

    for(int i=0; i < width*height; ++i)
        scacchiera[i] = nullptr;
}

void Scacchiera::destroy()
{
    for(int i=0;i<width*height;++i)
        delete scacchiera[i];
}

void Scacchiera::copy(const Scacchiera& s)
{
    width=s.width;
    height=s.height;
    scacchiera=new Pedina*[width*height];
    for(int i=0; i < width*height; ++i)
        scacchiera[i]=s.scacchiera[i];
}

Scacchiera::Scacchiera(const Scacchiera& s)
{
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