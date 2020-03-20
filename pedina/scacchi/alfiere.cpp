#include "alfiere.h"

Alfiere::Alfiere(Colore _colore,short int _x,short int _y):PedinaScacchi(_colore,_x,_y){}

bool Alfiere::controlloMossa(short int _x,short int _y)const
{
    return ((_x+_y)==getX()+getY()) || ((_x-_y)==getX()-getY());
};