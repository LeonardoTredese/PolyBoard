#include "pedone.h"

Pedone::Pedone(ColoreBN _colore, bool _primaMossa)
    : PedinaScacchi(_colore), primaMossa(_primaMossa){}

bool Pedone::controlloMossa(short int xI, short int yI, short int xF, short int yF, bool eat) const{
    if(eat)
    {
        if(getColore() == bianco)
            return yF==yI+1 && (xF==xI+1 || xF==xI-1);
        else
            return yF==yF-1 && (xF==xI+1 || xF==xI-1);
    }
    else
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

ID Pedone::getId() const
{
    return ID('P',getColore());
}

void Pedone::fattaPrimaMossa(){ primaMossa=false; }

bool Pedone::getPrimaMossa() const { return primaMossa; }