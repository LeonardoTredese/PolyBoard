#ifndef PEDONE_H
#define PEDONE_H
#include "pedinascacchi.h"

class Pedone: public PedinaScacchi
{
private:
    bool primaMossa;
public:
    Pedone(Colore _colore, short int _x, short int _y, bool _primaMossa=true);
    virtual bool controlloMossa(short int _x, short int _y) const;
};

#endif