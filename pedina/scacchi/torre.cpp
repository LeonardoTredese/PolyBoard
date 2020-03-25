#include "torre.h"

Torre::Torre(Colore _colore): PedinaScacchi(_colore) {}

bool Torre::controlloMossa(short int xI, short int yI, short int xF, short int yF) const
{
    return ((xF == xI && yF != yI) || (yF == yI && xF != xI));
}

Torre* Torre::clone() const
{
    return new Torre(*this);
}

std::string Torre::getId() const
{
    return PedinaScacchi::getId() + "R";
}