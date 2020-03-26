#include "torre.h"

Torre::Torre(ColoreBN _colore): PedinaScacchi(_colore) {}

bool Torre::controlloMossa(short int xI, short int yI, short int xF, short int yF, bool eat) const
{
    return ((xF == xI && yF != yI) || (yF == yI && xF != xI));
}

Torre* Torre::clone() const
{
    return new Torre(*this);
}

ID Torre::getId() const
{
    return ID('R', getColore());
}