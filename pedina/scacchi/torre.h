#ifndef TORRE_H
#define TORRE_H
#include "pedinascacchi.h"

class Torre: virtual public PedinaScacchi
{
public:
    Torre(ColoreBN _colore);
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const;
    virtual Torre* clone() const;
    virtual ID getId() const;
};

#endif