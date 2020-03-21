#ifndef SCACCHIERA_H
#define SCACCHIERA_H
#include "pedina.h"

//  EXCEPTION
enum ErroreScacchiera { BOARD_TOO_SMALL };

class Scacchiera
{
private:
    int width, height;
    Pedina** scacchiera;
    void destroy();
    void copy(const Scacchiera&);
public:
    Scacchiera(int _width, int _height);//CREA LA SCACCHIERA VUOTA
    ~Scacchiera();
    Scacchiera(const Scacchiera&);
    Scacchiera& operator=(const Scacchiera&);
    int getWidth() const;
    int getHeight() const;
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