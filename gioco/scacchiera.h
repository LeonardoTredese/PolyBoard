#ifndef SCACCHIERA_H
#define SCACCHIERA_H
#include "../pedina/pedina.h"

//EXCEPTION
enum ErroreScacchiera { BOARD_TOO_SMALL, ERR_CPY };

struct Posizione
{
    const int x;
    const int y;
    Posizione(int _x, int _y) : x(_x), y(_y){}
};

class Scacchiera
{
private:
    const int width, height;
    Pedina** scacchiera;
    void wipe();
    void copy(const Scacchiera&);
    Pedina*& elementAt(const Posizione& p) const;
    bool isInBound(const Posizione& p) const;
public:
    Scacchiera(int _width, int _height);
    ~Scacchiera();
    Scacchiera(const Scacchiera&);
    Scacchiera& operator=(const Scacchiera&);
    int getWidth() const;
    int getHeight() const;
    bool insert(const Pedina& toInsert, const Posizione& p);    // ritorna true sse è stato possibile inserire una nuova pedina nella posizione (x,y), i.e. la posizione era libera
    void remove(const Posizione& p);  //serve per rimuovere la pedina in posizione (x,y)
    bool move(const Posizione& from, const Posizione& to);  // scambia le posizioni tra due pedine (x1, y1) <--> (x2, y2)
    void moveAndEat(const Posizione& from, const Posizione& to);
    bool isFree(const Posizione& p) const;    //ritorna true sse nella posizione (x,y) non vi è nessuna pedina
    Posizione find(const Pedina* p) const;
    bool traiettoriaLibera(const Posizione& p1, const Posizione& p2) const;

    class iterator;
    class const_iterator;
    iterator begin() const;
    iterator end() const;
};

class Scacchiera::iterator
{
    friend class Scacchiera::const_iterator;
private:
    Pedina** p;
public:
    iterator(Pedina**);
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);
    Pedina*& operator*();
    Pedina** operator->();
    Pedina*& operator[](int);
    bool operator==(const iterator&);
    bool operator!=(const iterator&);
};

class Scacchiera::const_iterator
{
private:
    const Pedina** p; // punta ad un puntatore costante
public:
    const_iterator(Pedina** const);
    const_iterator(const iterator&);
    const_iterator& operator++();
    const_iterator operator++(int);
    const_iterator& operator--();
    const_iterator operator--(int);
    const Pedina*& operator*();
    const Pedina** operator->();
    const Pedina*& operator[](int);
    bool operator==(const const_iterator&);
    bool operator!=(const const_iterator&);
};

#endif