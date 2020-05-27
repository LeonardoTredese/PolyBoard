#ifndef PEDONE_H
#define PEDONE_H
#include "pedinascacchi.h"

class Pedone: public PedinaScacchi
{
public:
    Pedone(Colore colore, bool primaMossa=true);
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const;
    virtual Pedone* clone() const;
    virtual ID getId() const;
};

#endif
