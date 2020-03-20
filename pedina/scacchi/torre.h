#ifndef TORRE_H
#define TORRE_H
#include "pedinascacchi.h"

class Torre: virtual public PedinaScacchi
{
public:
    Torre(Colore _colore, short int _x, short int _y);
    virtual bool controlloMossa(short int _x, short int _y) const;
};

#endif