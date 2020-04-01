#ifndef SCACCHIERA_H
#define SCACCHIERA_H
#include "posizione.h"

//EXCEPTION
enum ErroreScacchiera { BOARD_TOO_SMALL, ERR_CPY };

template<class T>
class Scacchiera
{
private:
    const unsigned int width, height;
    T** board;
    
    T*& elementAt(const Posizione& p) const
    {
        return board[width*p.y+p.x];
    }
    bool isInBound(const Posizione& p) const
    {
        return p.x >= 0 && p.x < width && p.y >= 0 && p.y < height;
    }
public:
    Scacchiera(unsigned int _width, unsigned int _height) : width(_width), height(_height)
    {
        if(width < 2 || height < 2)
            throw ErroreScacchiera(BOARD_TOO_SMALL);
        board = new T*[width*height](nullptr);
    }
    ~Scacchiera()
    {
        for(int i=0; i<width*height; ++i)
            delete board[i];
        delete[] board;
    }
    Scacchiera(const Scacchiera& s)
        : width(s.width), height(s.height), board(new T*[width*height])
    {
        for(int i=0; i<width*height; ++i)
            board[i] = s.board[i] ? new T(*s.board[i]) : nullptr;
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
                board[i] = s.board[i] ? new T(*s.board[i]) : nullptr;
            }
        }
        return *this;
    }
    
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    bool insert(const T& toInsert, const Posizione& p)    // ritorna true sse è stato possibile inserire una nuova pedina nella posizione (x,y), i.e. la posizione era libera
    {
        if(isFree(p))
        {
            elementAt(p) = new T(toInsert);
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
    bool move(const Posizione& from, const Posizione& to)  // scambia le posizioni tra due pedine (x1, y1) <--> (x2, y2)
    {
        if(isFree(to) && isInBound(from))
        {
            elementAt(to)=elementAt(from);
            elementAt(from)=nullptr;
            return true;
        }
        else
            return false;
    }
    bool moveForce(const Posizione& from, const Posizione& to) // CAMBIATO
    {
        remove(to);
        return move(from,to);
    }
    bool isFree(const Posizione& p) const    //ritorna true sse nella posizione (x,y) non vi è nessuna pedina
    {
        if(!isInBound(p))
            return false;
        return elementAt(p)==nullptr;
    }
    Posizione find(const T* p) const
    {
        for(int y=0; y < height; ++y)
            for(int x=0; x < width; ++x)
            {
                Posizione pos(x,y);
                if(p == elementAt(pos))
                    return pos;
            }
    }

    bool traiettoriaLibera(const Posizione& p1, const Posizione& p2) const; // TODO

    class iterator
    {
        friend class Scacchiera::const_iterator;
        private:
            T** p;
        public:
            iterator(T** _p): p(_p){}
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
            T*& operator*() const { return *p; }
            T** operator->() const { return p; }
            bool operator==(const iterator& it) const { return p == it.p; }
            bool operator!=(const iterator& it) const { return p != it.p; }
    };

    class const_iterator
    {
    private:
        const T** p; // punta ad un puntatore costante
    public:
        const_iterator(T** const _p): p(_p) {}
        const_iterator(const iterator& it): p(it.p) {}
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
        const T*& operator*() const { return *p; }
        const T** operator->() const { return p; }
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