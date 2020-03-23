#ifndef TORRE_H
#define TORRE_H
#include "pedinascacchi.h"

class Torre: virtual public PedinaScacchi
{
public:
    Torre(Colore _colore);
    virtual bool controlloMossa(short int xI, short yI, short int xF, short int yF) const;
    virtual Torre* clone() const;
};

#endif