#include "re.h"

Re::Re(Colore _colore, short int _x, short int _y):PedinaScacchi(_colore,_x,_y){}


bool Re::controlloMossa(short int _x, short int _y) const{
    short int x=getX(), y=getY();
    return !(x==_x && y==_y) && ((_x-1==x || _x+1==x || _x==x) && (_y-1==y || _y+1==y || _y==y));
}
