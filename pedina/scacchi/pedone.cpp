#include "pedone.h"

Pedone::Pedone(Colore _colore, bool _primaMossa)
    : PedinaScacchi(_colore), primaMossa(_primaMossa){}

bool Pedone::controlloMossa(short int xI,short int yI,short int xF,short int yF) const{
    if(getColore()==bianco) // parte da sotto
        if(primaMossa)
            return yF==yI-1 || yF==yI-2;
        else
            return yF==yI-1;
    else                    // parte da sopra
        if(primaMossa)
            return yF==yI+1 || yF==yI+2;
        else
            return yF==yI+1;
}

Pedone* Pedone::clone() const
{
    return new Pedone(*this);
}