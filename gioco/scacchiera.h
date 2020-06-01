#ifndef SCACCHIERA_H
#define SCACCHIERA_H
#include "../posizione.h"
#include "../pedina/pedina.h"
#include <list>
using std::list;

//EXCEPTION
enum ErroreScacchiera { BOARD_TOO_SMALL, ERR_CPY, ELEMENT_NOT_FOUND };

class Scacchiera
{
private:
    const int width, height;
    Pedina** board;
    Pedina*& elementAt(const Posizione& p) const;
public:
    Scacchiera(int _width, int _height);
    ~Scacchiera();
    Scacchiera(const Scacchiera& s);
    Scacchiera& operator=(const Scacchiera& s);
    Pedina* operator[](const Posizione&) const;
    int getWidth() const;
    int getHeight() const;
    bool isInBound(const Posizione& p) const;
    bool insert(const Pedina& toInsert, const Posizione& p); // ritorna true sse è stato possibile inserire una nuova pedina nella posizione (x,y), i.e. la posizione era libera
    void remove(const Posizione& p);  //serve per rimuovere la pedina in posizione (x,y)
    bool move(const Posizione& from, const Posizione& to, bool force=true);  // sposta la pedina in posizione "from" in posizione "to"
    bool isFree(const Posizione& p) const;    //ritorna true sse nella posizione (x,y) non vi è nessuna pedina
    Posizione find(const Pedina* p) const;

    // PRE: l'ultima posizione della lista di posizioni è quella di arrivo
    bool traiettoriaLibera(const list<Posizione>& posizioni) const;
    //POST: ritorna true sse tutte le posizioni, tranne l'ultima sono libere.
    class const_iterator;
    class iterator
    {
        friend class Scacchiera::const_iterator;
        friend class Scacchiera;
        private:
            Pedina** p;
            iterator(Pedina** _p);
        public:
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
        const Pedina* const* p;  // puntatore non costante a puntatore costante a Pedina costante
    public:
        const_iterator(const iterator& it);
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        const Pedina* const& operator*() const;
        const Pedina* const* operator->() const;
        bool operator==(const const_iterator& cit) const;
        bool operator!=(const const_iterator& cit) const;
    };
    iterator begin() const;
    iterator end() const;
};

#endif
