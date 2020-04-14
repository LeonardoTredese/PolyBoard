#ifndef PEDONE_H
#define PEDONE_H
#include "pedinascacchi.h"

class Pedone: public PedinaScacchi
{
private:
    bool primaMossa;//indica se la prima mossa è stata effettuata 1 se deve essere ancora spostata, 0 altrimenti
public:
    Pedone(Colore _colore, bool _primaMossa=true);
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const;
    virtual Pedone* clone() const;
    virtual ID getId() const;
    virtual void pedinaMossa();
};

#endif
