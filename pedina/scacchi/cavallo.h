#ifndef CAVALLO_H
#define CAVALLO_H
#include "pedinascacchi.h"

class Cavallo: public PedinaScacchi
{
public:
    Cavallo(Colore _colore);
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const;
    virtual Cavallo* clone() const;
    virtual ID getId() const;
};

#endif