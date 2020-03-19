#include "torre.h"

Torre::Torre(bool _colore, short int _x, short int _y): PedinaScacchi(_colore, _x, _y) {}

bool Torre::muovi(short int _x, short int _y)
{
    if(_x == getX() && _y != getY())
    {
        setY(_y);
        return true;
    }
    else if(_y == getY() && _x != getX())
    {
        setX(_x);
        return true;
    }
    return false;
}