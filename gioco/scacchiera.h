#ifndef SCACCHIERA_H
#define SCACCHIERA_H
#include "../posizione.h"
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
    Pedina*& elementAt(const Posizione& p) const;
public:
    Scacchiera(unsigned int _width, unsigned int _height);
    ~Scacchiera();
    Scacchiera(const Scacchiera& s);
    Scacchiera& operator=(const Scacchiera& s);
    Pedina* operator[](const Posizione&) const;
    int getWidth() const;
    int getHeight() const;
    bool isInBound(const Posizione& p) const;
    bool insert(const Pedina& toInsert, const Posizione& p); // ritorna true sse è stato possibile inserire una nuova pedina nella posizione (x,y), i.e. la posizione era libera
    void remove(const Posizione& p);  //serve per rimuovere la pedina in posizione (x,y)
    bool move(const Posizione& from, const Posizione& to, bool force=true);  // sposta la pedina in posizione from in posizione --> to
    bool isFree(const Posizione& p) const;    //ritorna true sse nella posizione (x,y) non vi è nessuna pedina
    Posizione find(const Pedina* p) const;
    //Pedina& selectElement(const Posizione& p) const;

    // PRE: posizioni è una lista di posizioni valide non vuota e ultima posizione è quella di arrivo
    bool traiettoriaLibera(const list<Posizione>& posizioni) const;
    //POST: ritorna true sse tutte le posizioni, tranne l'ultima sono libere.
    class const_iterator;
    class iterator
    {
        friend class Scacchiera::const_iterator;
        private:
            Pedina** p;
        public:
            iterator(Pedina** _p);
            iterator& operator++();
            iterator operator++(int);
            iterator& operator--();
            iterator operator--(int);
            Pedina*& operator*() const;
            Pedina** operator->() const;
            bool operator==(const iterator& it) const;
            bool operator!=(const iterator& it) const;
    };

    class const_iterator
    {
    private:
        const Pedina** p; // punta ad un puntatore costante
    public:
        const_iterator(const Pedina** _p);
        const_iterator(const iterator& it);
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        const Pedina*& operator*() const;
        const Pedina** operator->() const;
        bool operator==(const const_iterator& cit) const;
        bool operator!=(const const_iterator& cit) const;
        // return Y = (p - board)/width   X = (p-board)%width
    };
    iterator begin() const;
    iterator end() const;
};

#endif
