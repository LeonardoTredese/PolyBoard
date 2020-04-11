#ifndef MOVIMENTO_CROCE_H
#define MOVIMENTO_CROCE_H
#include "pedinascacchi.h"
class MovimentoCroce : virtual public PedinaScacchi
{
public:
    MovimentoCroce(Colore _colore);
    virtual MovimentoCroce* clone()const = 0;
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const;
};
#endif