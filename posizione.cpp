#include "posizione.h"

Posizione::Posizione(int _x, int _y) : x(_x), y(_y){}

Posizione Posizione::operator+(const Posizione& p) const { return Posizione(x + p.x, y + p.y); }

Posizione Posizione::operator*(int value) const
{
    return Posizione(x*value, y*value);
}

bool Posizione::operator!=(const Posizione& p) const
{
    return p.x != x || p.y != y;
}

bool Posizione::operator==(const Posizione& p)const
{
    return p.x == x && p.y == y;
}