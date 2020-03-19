#include "pedina.h"

Pedina::Pedina(short int _x, short int _y)
    : x(_x), y(_y)
{
    // TODO: exception in x y -> bad_position
    
}
Pedina::~Pedina(){}
short int Pedina::getX() const{return x;}
short int Pedina::getY() const{return y;}
void Pedina::setX(short int _x){x=_x;}
void Pedina::setY(short int _y){y=_y;}
