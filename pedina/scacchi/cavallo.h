#ifndef CAVALLO_H
#define CAVALLO_H
#include "pedinascacchi.h"

class Cavallo: public PedinaScacchi
{
public:
    Cavallo(Colore _colore, short int _x, short int _y);
    virtual bool controlloMossa(short int _x, short int _y) const;
};

#endif