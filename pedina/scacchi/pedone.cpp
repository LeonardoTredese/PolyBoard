#include "pedone.h"

Pedone::Pedone(Colore _colore, short int _x, short int _y, bool _primaMossa)
    : PedinaScacchi(_colore, _x, _y), primaMossa(_primaMossa){}

bool Pedone::controlloMossa(short int _x, short int _y) const{
    short int y=getY();
    if(getColore()==bianco) // parte da sotto
        if(primaMossa)
            return _y==y-1 || _y==y-2;
        else
            return _y==y-1;
    else                    // parte da sopra
        if(primaMossa)
            return _y==y+1 || _y==y+2;
        else
            return _y==y+1;
}