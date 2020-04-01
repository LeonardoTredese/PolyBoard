#ifndef REGINA_H
#define REGINA_H
#include "torre.h"
#include "alfiere.h"

class Regina: public Torre, public Alfiere{
public:
    Regina(Colore _colore);
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const;
    virtual Regina* clone() const;
    virtual ID getId() const;
};

#endif