#ifndef TORRE_H
#define TORRE_H
#include "movimentoCroce.h"

class Torre: virtual public MovimentoCroce
{
public:
    Torre(Colore _colore);
    virtual Torre* clone() const;
    virtual ID getId() const;
};

#endif