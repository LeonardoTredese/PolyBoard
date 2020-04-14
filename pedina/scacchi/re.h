#ifndef RE_H
#define RE_H
#include "pedinascacchi.h"

class Re: public PedinaScacchi{
private:
    bool primaMossa;//indica se la prima mossa è stata effettuata 1 se deve essere ancora spostata, 0 altrimenti
public:
    Re(Colore _colore, bool _primaMossa=true);
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const;
    virtual Re* clone() const;
    virtual ID getId() const;
    virtual void pedinaMossa();
};

#endif