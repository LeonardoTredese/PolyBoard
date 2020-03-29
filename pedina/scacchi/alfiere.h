#ifndef ALFIERE_H
#define ALFIERE_H
#include "pedinascacchi.h"
class Alfiere: virtual public PedinaScacchi
{
public:
    Alfiere(ColoreBN _colore);
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const;
    virtual Alfiere* clone() const;
    virtual ID getId()const;
};
#endif