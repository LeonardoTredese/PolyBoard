#include "cavallo.h"

Cavallo::Cavallo(Colore _colore, short int _x, short int _y):PedinaScacchi(_colore, _x, _y){}

bool Cavallo::controlloMossa(short int _x, short int _y) const
{
    short int x=getX(), y=getY();
    return (((x+2==_x)||(x-2==_x))&&((y+1==_y)||(y-1==_y))) || (((y+2==_y)||(y-2==_y))&&((x+1==_x)||(x-1==_x)));
    //che svarion
}