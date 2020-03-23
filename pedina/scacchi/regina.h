#ifndef REGINA_H
#define REGINA_H
#include "torre.h"
#include "alfiere.h"

class Regina: public Torre, public Alfiere{
public:
    Regina(Colore _colore);
    virtual bool controlloMossa(short int xI,short int yI,short int xF,short int yF) const;
    virtual Regina* clone() const;
};

#endif