#include "alfiere.h"

Alfiere::Alfiere(Colore _colore):PedinaScacchi(_colore){}

bool Alfiere::controlloMossa(short int xI,short int yI,short int xF,short int yF)const
{
    return (xF+yF==xI+yI || (xF-yF==xI-yI));
};