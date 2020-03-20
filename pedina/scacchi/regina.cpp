#include "regina.h"

Regina::Regina(Colore _colore, short int _x, short int _y)
    : PedinaScacchi(_colore, _x, _y), Torre(_colore, _x, _y), Alfiere(_colore, _x, _y){}

bool Regina::controlloMossa(short int xI,short int yI,short int xF,short int yF) const{
    return Torre::controlloMossa(xI, yI, xF, yF) || Alfiere::controlloMossa(xI, yI, xF, yF);
}