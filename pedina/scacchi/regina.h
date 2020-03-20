#ifndef REGINA_H
#define REGINA_H
#include "torre.h"
#include "alfiere.h"

class Regina: public Torre, public Alfiere{
public:
    Regina(Colore _colore, short int _x, short int _y);
    bool controlloMossa(short int _x, short int _y) const;
};

#endif