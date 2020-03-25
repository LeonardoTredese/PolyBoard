#ifndef CAVALLO_H
#define CAVALLO_H
#include "pedinascacchi.h"

class Cavallo: public PedinaScacchi
{
public:
    Cavallo(ColoreBN _colore);
    virtual bool controlloMossa(short int xI, short int yI, short int xF, short int yF) const;
    virtual Cavallo* clone() const;
    virtual ID getId() const;
};

#endif