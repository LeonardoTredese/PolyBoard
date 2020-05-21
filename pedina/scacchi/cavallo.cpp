#include "cavallo.h"

Cavallo::Cavallo(Colore _colore):PedinaScacchi(_colore){}

std::list<Posizione> Cavallo::controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat) const
{
    std::list<Posizione> ris;
    if((( inizio.x+2 == fine.x || inizio.x-2==fine.x ) && ( inizio.y+1==fine.y || inizio.y-1==fine.y )) || 
    (( inizio.y+2==fine.y || inizio.y-2==fine.y )&&((inizio.x+1==fine.x)||(inizio.x-1==fine.x))))
        ris.push_back(fine);
    return ris;
}

Cavallo* Cavallo::clone()const
{
    return new Cavallo(*this);
}

ID Cavallo::getId() const
{
    return ID('N', getColore());
}
