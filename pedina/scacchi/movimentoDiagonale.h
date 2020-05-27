#ifndef MOVIMENTO_DIAGONALE_H
#define MOVIMENTO_DIAGONALE_H
#include "pedinascacchi.h"

class MovimentoDiagonale : virtual public PedinaScacchi
{
public:
    MovimentoDiagonale(Colore colore, bool primaMossa = true);
    virtual MovimentoDiagonale* clone() const = 0;
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const;
};

#endif