#ifndef RE_H
#define RE_H
#include "pedinascacchi.h"

class Re: public PedinaScacchi{
public:
    Re(ColoreBN _colore);
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const;
    virtual Re* clone() const;
    virtual ID getId() const;
};

#endif