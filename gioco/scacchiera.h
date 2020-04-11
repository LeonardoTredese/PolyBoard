#ifndef SCACCHIERA_H
#define SCACCHIERA_H
#include "posizione.h"
#include "../pedina/pedina.h"
#include <list>
using std::list;

//EXCEPTION
enum ErroreScacchiera { BOARD_TOO_SMALL, ERR_CPY, ELEMENT_NOT_FOUND };

/*
Il contenitore Scacchiera, nel caso venisse dereferenziato ritornerebbe un T*,
in quanto nella Scaccchiera è necessario tenere conto delle posizioni nulle
in quanto sono utili per tutti i metodi necessari ad implementare la Scacchiera
e per gestire le mosse delle pedine.
Sono stati esaminati anche altri tipi di contenitore, ma tutti portavano allo stesso problema,
ovvero come rappresentare una casella vuota per un generico oggetto T.
è stato scelto quindi di permettere un'istanziazione ad oggetto ma gestirlo come puntatore, in quanto
se gestissimo un array di T dentro il template non sarebbero possibili metodi come isFree e tutti quelli che lo usano.
Perciò abbiamo deciso di mantenere questa implementazione, in quanto ci è sembrata la più opportuna per il nostro scopo.
*/

class Scacchiera
{
private:
    const unsigned int width, height;
    Pedina** board;
    Pedina*& elementAt(const Posizione& p) const
    {
        return board[width*p.y+p.x];
    }
public:
    Scacchiera(unsigned int _width, unsigned int _height) : width(_width), height(_height)
    {
        if(width < 2 || height < 2)
            throw ErroreScacchiera(BOARD_TOO_SMALL);
        board = new Pedina*[width*height];
        for(int i=0; i<width*height; ++i)
            board[i] = nullptr;
    }
    ~Scacchiera()
    {
        for(int i=0; i<width*height; ++i)
            delete board[i];
        delete[] board;
    }
    Scacchiera(const Scacchiera& s)
        : width(s.width), height(s.height), board(new Pedina*[width*height])
    {
        for(int i=0; i<width*height; ++i)
            board[i] = s.board[i] ? s.board[i]->clone() : nullptr;
    }
    Scacchiera& operator=(const Scacchiera& s)
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
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    bool isInBound(const Posizione& p) const
    {
        return p.x >= 0 && p.x < width && p.y >= 0 && p.y < height;
    }
    bool insert(const Pedina& toInsert, const Posizione& p)    // ritorna true sse è stato possibile inserire una nuova pedina nella posizione (x,y), i.e. la posizione era libera
    {
        if(isFree(p))
        {
            elementAt(p) = toInsert.clone();
            return true;
        }
        else
            return false;
    }
    void remove(const Posizione& p)  //serve per rimuovere la pedina in posizione (x,y)
    {
        if(isInBound(p))
        {
            delete elementAt(p);
            elementAt(p)=nullptr;
        }
    }
    bool move(const Posizione& from, const Posizione& to, bool force=true)  // sposta la pedina in posizione from in posizione --> to
    {
        if(isInBound(from) && isInBound(to))
        {
            if(force)
                remove(to);
            if(force || isFree(to))
            {
                elementAt(to)=elementAt(from);
                elementAt(from)=nullptr;
                return true;
            }
        }
        return false;
    }
    bool isFree(const Posizione& p) const    //ritorna true sse nella posizione (x,y) non vi è nessuna pedina
    {
        if(!isInBound(p))
            return false;
        return elementAt(p)==nullptr;
    }
    Posizione find(const Pedina* p) const
    {
        for(int y=0; y < height; ++y)
            for(int x=0; x < width; ++x)
            {
                Posizione pos(x,y);
                if(p == elementAt(pos))
                    return pos;
            }
    }
    Pedina& selectElement(const Posizione& p) const
    {
        if(!isInBound(p) || elementAt(p) == nullptr)
            throw(ELEMENT_NOT_FOUND);
        else
            return *elementAt(p);
    }

    // PRE: posizioni è una lista di posizioni valide non vuota e ultima posizione è quella di arrivo
    bool traiettoriaLibera(const list<Posizione>& posizioni) const
    {
        auto end = posizioni.end();
        --end;
        for(auto cit=posizioni.begin(); cit != end; ++cit) // non controllo l'ultima casella
            if(!isFree(*cit))
                return false;
        return true;
    }
    //POST: ritorna true sse tutte le posizioni, tranne l'ultima sono libere.
    class const_iterator;

    class iterator
    {
        friend class Scacchiera::const_iterator;
        private:
            Pedina** p;
        public:
            iterator(Pedina** _p): p(_p){}
            iterator& operator++()
            {
                ++p;
                return *this;
            }
            iterator operator++(int)
            {
                iterator it(*this);
                ++p;
                return it;
            }

            iterator& operator--()
            {
                --p;
                return *this;
            }
            iterator operator--(int)
            {
                Scacchiera::iterator it(*this);
                --p;
                return it;
            }
            Pedina*& operator*() const { return *p; }
            Pedina** operator->() const { return p; }
            bool operator==(const iterator& it) const { return p == it.p; }
            bool operator!=(const iterator& it) const { return p != it.p; }
    };

    class const_iterator
    {
    private:
        const Pedina** p; // punta ad un puntatore costante
    public:
        const_iterator(Pedina** const _p): p(_p) {}
        const_iterator(const iterator& it): p(const_cast<const Pedina**>(it.p)) {} // TODO: trovare soluzione
        const_iterator& operator++()
        {
            ++p;
            return *this;
        }
        const_iterator operator++(int)
        {
            const_iterator cit(*this);
            ++p;
            return cit;
        }
        const_iterator& operator--()
        {
            --p;
            return *this;
        }
        const_iterator operator--(int)
        {
            const_iterator cit(*this);
            --p;
            return cit;
        }
        const Pedina*& operator*() const { return *p; }
        const Pedina** operator->() const { return p; }
        bool operator==(const const_iterator& cit) const { return p == cit.p; }
        bool operator!=(const const_iterator& cit) const { return p != cit.p; }
    };
    iterator begin() const
    {
        return iterator(board);
    }
    iterator end() const
    {
        return iterator(board+width*height);
    }
};

#endif
