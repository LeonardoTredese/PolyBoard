#ifndef PEDONE_H
#define PEDONE_H
#include "pedinascacchi.h"

class Pedone: public PedinaScacchi
{
private:
    bool primaMossa;
public:
    Pedone(bool _colore, short int _x, short int _y, bool _primaMossa=true);
    virtual bool muovi(short int _x, short int _y);
};

#endif