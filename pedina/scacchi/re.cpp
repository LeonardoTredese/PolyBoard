#include "re.h"

Re::Re(bool _colore, short int _x, short int _y):PedinaScacchi(_colore,_x,_y){}


bool Re::muovi(short int _x, short int _y) {
    if ((_x-1==getX() || _x+1==getX() || _x==getX()) && (_y-1==getY() || _y+1==getY() || _y==getY())){
        setX(_x);
        setY(_y);
        return true;
    }
    else
        return false;
}
