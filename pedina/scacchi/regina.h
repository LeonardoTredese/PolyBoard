#ifndef REGINA_H
#define REGINA_H
#include "movimentoCroce.h"
#include "movimentoDiagonale.h"

class Regina: public MovimentoCroce, public MovimentoDiagonale{
public:
    Regina(Colore _colore);
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const;
    virtual Regina* clone() const;
    virtual ID getId() const;
};

#endif