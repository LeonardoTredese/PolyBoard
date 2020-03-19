#ifndef RE_H
#define RE_H
#include "pedinascacchi.h"

class Re: public PedinaScacchi{
public:
    Re(bool _colore, short int _x, short int _y);
    virtual bool muovi(short int _x, short int _y);
};

#endif