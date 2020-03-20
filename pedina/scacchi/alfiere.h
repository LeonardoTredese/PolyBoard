#ifndef ALFIERE_H
#define ALFIERE_H
#include "pedinascacchi.h"
class Alfiere: virtual public PedinaScacchi
{
public:
    Alfiere(Colore _colore,short int _x,short int _y);
    virtual bool controlloMossa(short int _x,short int _y)const;
};
#endif