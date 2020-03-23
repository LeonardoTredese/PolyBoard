#include "regina.h"

Regina::Regina(Colore _colore)
    : PedinaScacchi(_colore), Torre(_colore), Alfiere(_colore){}

bool Regina::controlloMossa(short int xI,short int yI,short int xF,short int yF) const{
    return Torre::controlloMossa(xI, yI, xF, yF) || Alfiere::controlloMossa(xI, yI, xF, yF);
}

Regina* Regina::clone() const
{
    return new Regina(*this);
}