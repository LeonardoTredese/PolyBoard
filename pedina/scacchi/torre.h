#ifndef TORRE_H
#define TORRE_H
#include "pedinascacchi.h"

class Torre: virtual public PedinaScacchi
{
public:
    Torre(bool _colore, short int _x, short int _y);
    virtual bool muovi(short int _x, short int _y);
};

#endif