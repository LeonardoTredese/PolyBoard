#include "torre.h"

Torre::Torre(Colore _colore, short int _x, short int _y): PedinaScacchi(_colore, _x, _y) {}

bool Torre::controlloMossa(short int _x, short int _y) const
{
    return ((_x == getX() && _y != getY()) || (_y == getY() && _x != getX()));
}