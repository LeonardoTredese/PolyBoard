#ifndef RE_H
#define RE_H
#include "pedinascacchi.h"

class Re: public PedinaScacchi{
public:
    Re(Colore _colore);
    virtual bool controlloMossa(short int xI,short int yI,short int xF,short int yF) const;
};

#endif