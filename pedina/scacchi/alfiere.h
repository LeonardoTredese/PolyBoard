#ifndef ALFIERE_H
#define ALFIERE_H
#include "pedinascacchi.h"
class Alfiere: virtual public PedinaScacchi
{
public:
    Alfiere(Colore _colore);
    virtual bool controlloMossa(short int xI,short int yI,short int xF,short int yF) const;
    virtual Alfiere* clone() const;
    virtual std::string getId()const;
};
#endif