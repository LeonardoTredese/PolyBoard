#ifndef RE_H
#define RE_H
#include "pedinascacchi.h"

class Re: public PedinaScacchi{
public:
    Re(Colore _colore, short int _x, short int _y);
    virtual bool controlloMossa(short int _x, short int _y) const;
};

#endif