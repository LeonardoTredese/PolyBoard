 #include "alfiere.h"

Alfiere::Alfiere(ColoreBN _colore):PedinaScacchi(_colore){}

bool Alfiere::controlloMossa(short int xI,short int yI,short int xF,short int yF, bool eat)const
{
    return (xF+yF==xI+yI || (xF-yF==xI-yI));
};

Alfiere* Alfiere::clone() const
{
    return new Alfiere(*this);
}

ID Alfiere::getId() const
{
    return ID('B', getColore());
}