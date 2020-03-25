#ifndef ALFIERE_H
#define ALFIERE_H
#include "pedinascacchi.h"
class Alfiere: virtual public PedinaScacchi
{
public:
    Alfiere(ColoreBN _colore);
    virtual bool controlloMossa(short int xI,short int yI,short int xF,short int yF) const;
    virtual Alfiere* clone() const;
    virtual ID getId()const;
};
#endif