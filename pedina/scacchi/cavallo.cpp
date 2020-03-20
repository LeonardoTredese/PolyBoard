#include "cavallo.h"

Cavallo::Cavallo(Colore _colore):PedinaScacchi(_colore){}

bool Cavallo::controlloMossa(short int xI, short int yI, short int xF, short int yF) const
{
    return (((xI+2==xF)||(xI-2==xF))&&((yI+1==yF)||(yI-1==yF))) || (((yI+2==yF)||(yI-2==yF))&&((xI+1==xF)||(xI-1==xF)));
}