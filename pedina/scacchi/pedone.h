#ifndef PEDONE_H
#define PEDONE_H
#include "pedinascacchi.h"

class Pedone: public PedinaScacchi
{
private:
    bool primaMossa;
public:
    Pedone(ColoreBN _colore, bool _primaMossa=true);
    virtual bool controlloMossa(short int xI, short int yI, short int xF, short int yF, bool eat=false) const;
    virtual Pedone* clone() const;
    virtual ID getId() const;
    void fattaPrimaMossa();
    bool getPrimaMossa() const;
};

#endif