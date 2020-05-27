#ifndef ALFIERE_H
#define ALFIERE_H
#include "movimentoDiagonale.h"

class Alfiere: public MovimentoDiagonale
{
public:
    Alfiere(Colore _colore, bool primaMossa = true);
    virtual Alfiere* clone() const;
    virtual ID getId()const;
};
#endif