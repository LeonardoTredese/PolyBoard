#ifndef SCACCHIERA_H
#define SCACCHIERA_H
#include "../pedina/pedina.h"

//EXCEPTION
enum ErroreScacchiera { BOARD_TOO_SMALL, ERR_CPY };

class Scacchiera
{
private:
    const int width, height;
    Pedina** scacchiera;
    void destroy();
    void copy(const Scacchiera&);
    Pedina*& elementAt(int x, int y) const; // TODO: POTREBBE ANDARE IN PUBLIC? CHI LO SA?
public:
    Scacchiera(int _width, int _height);
    ~Scacchiera();
    Scacchiera(const Scacchiera&);
    Scacchiera& operator=(const Scacchiera&);
    int getWidth() const;
    int getHeight() const;
    bool insert(const Pedina& toInsert, int x, int y);    // ritorna true sse è stato possibile inserire una nuova pedina nella posizione (x,y), i.e. la posizione era libera
    void remove(int x, int y);  //serve per rimuovere la pedina in posizione (x,y)
    bool move(int x1, int y1, int x2, int y2);  // scambia le posizioni tra due pedine (x1, y1) <--> (x2, y2)
    void moveAndEat(int x1, int y1, int x2, int y2);
    bool isFree(int x, int y) const;    //ritorna true sse nella posizione (x,y) non vi è nessuna pedina
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
};

#endif