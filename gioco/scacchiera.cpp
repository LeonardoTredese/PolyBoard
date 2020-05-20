#include "scacchiera.h"

Pedina*& Scacchiera::elementAt(const Posizione& p) const
{
    return board[width*p.y+p.x];
}
Scacchiera::Scacchiera(int _width, int _height) : width(_width), height(_height)
{
    if(width < 2 || height < 2)
        throw ErroreScacchiera(BOARD_TOO_SMALL);
    board = new Pedina*[width*height];
    for(int i=0; i<width*height; ++i)
        board[i] = nullptr;
}
Scacchiera::~Scacchiera()
{
    for(int i=0; i<width*height; ++i)
        delete board[i];
    delete[] board;
}
Scacchiera::Scacchiera(const Scacchiera& s)
    : width(s.width), height(s.height), board(new Pedina*[width*height])
{
    for(int i=0; i<width*height; ++i)
        board[i] = s.board[i] ? s.board[i]->clone() : nullptr;
}
Scacchiera& Scacchiera::operator=(const Scacchiera& s)
{
    if(this != &s)
    {
        if(width != s.width || height != s.height)
            throw ErroreScacchiera(ERR_CPY);
        for(int i=0; i<width*height; ++i)
        { 
            delete board[i];
            board[i] = s.board[i] ? s.board[i]->clone() : nullptr;
        }
    }
    return *this;
}

Pedina* Scacchiera::operator[](const Posizione& p) const
{
    return elementAt(p); // tavolo[Posizione(x,y)] ?= tavolo[x,y]
}

int Scacchiera::getWidth() const { return width; }
int Scacchiera::getHeight() const { return height; }
bool Scacchiera::isInBound(const Posizione& p) const
{
    return p.x >= 0 && p.x < width && p.y >= 0 && p.y < height;
}
bool Scacchiera::insert(const Pedina& toInsert, const Posizione& p)    // ritorna true sse è stato possibile inserire una nuova pedina nella posizione (x,y), i.e. la posizione era libera
{
    if(isFree(p))
    {
        elementAt(p) = toInsert.clone();
        return true;
    }
    else
        return false;
}
void Scacchiera::remove(const Posizione& p)  //serve per rimuovere la pedina in posizione (x,y)
{
    if(isInBound(p))
    {
        delete elementAt(p);
        elementAt(p) = nullptr;
    }
}
bool Scacchiera::move(const Posizione& from, const Posizione& to, bool force)  // sposta la pedina in posizione from in posizione --> to
{
    if(isInBound(from) && isInBound(to))
    {
        if(force)
            remove(to); // con questo isFree(to) è sicuramente true
        if(isFree(to))
        {
            elementAt(to)=elementAt(from);
            elementAt(from)=nullptr;
            return true;
        }
    }
    return false;
}
bool Scacchiera::isFree(const Posizione& p) const    //ritorna true sse nella posizione (x,y) non vi è nessuna pedina
{
    if(!isInBound(p))
        return false;
    return elementAt(p)==nullptr;
}
Posizione Scacchiera::find(const Pedina* p) const
{
    for(int y=0; y < height; ++y)
        for(int x=0; x < width; ++x)
        {
            Posizione pos(x,y);
            if(p == elementAt(pos))
                return pos;
        }
    throw(ErroreScacchiera(ELEMENT_NOT_FOUND));
}

bool Scacchiera::traiettoriaLibera(const list<Posizione>& posizioni) const
{
    if(posizioni.empty())
        return false;
    auto end = posizioni.end();
    --end;
    for(auto cit=posizioni.begin(); cit != end; ++cit) // non controllo l'ultima casella
        if(!isFree(*cit))
            return false;
    return true;
}

//############################ ITERATOR ################################################
Scacchiera::iterator::iterator(Pedina** _p): p(_p){}
Scacchiera::iterator& Scacchiera::iterator::operator++()
{
    ++p;
    return *this;
}
Scacchiera::iterator Scacchiera::iterator::operator++(int)
{
    iterator it(*this);
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
Pedina*& Scacchiera::iterator::operator*() const { return *p; }
Pedina** Scacchiera::iterator::operator->() const { return p; }
bool Scacchiera::iterator::operator==(const iterator& it) const { return p == it.p; }
bool Scacchiera::iterator::operator!=(const iterator& it) const { return p != it.p; }

//##################################### CONST ITERATOR ###############################################
Scacchiera::const_iterator::const_iterator(const Pedina** _p): p(_p) {}
Scacchiera::const_iterator::const_iterator(const iterator& it) : p(const_cast<const Pedina**>(it.p)) {} // TODO: trovare soluzione
Scacchiera::const_iterator& Scacchiera::const_iterator::operator++()
{
    ++p;
    return *this;
}
Scacchiera::const_iterator Scacchiera::const_iterator::operator++(int)
{
    const_iterator cit(*this);
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
    const_iterator cit(*this);
    --p;
    return cit;
}
const Pedina*& Scacchiera::const_iterator::operator*() const { return *p; }
const Pedina** Scacchiera::const_iterator::operator->() const { return p; }
bool Scacchiera::const_iterator::operator==(const const_iterator& cit) const { return p == cit.p; }
bool Scacchiera::const_iterator::operator!=(const const_iterator& cit) const { return p != cit.p; }

Scacchiera::iterator Scacchiera::begin() const
{
    return Scacchiera::iterator(board);
}
Scacchiera::iterator Scacchiera::end() const
{
    return Scacchiera::iterator(board+width*height);
}
