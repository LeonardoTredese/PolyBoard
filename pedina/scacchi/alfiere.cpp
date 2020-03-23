 #include "alfiere.h"

Alfiere::Alfiere(Colore _colore):PedinaScacchi(_colore){}

bool Alfiere::controlloMossa(short int xI,short int yI,short int xF,short int yF)const
{
    return (xF+yF==xI+yI || (xF-yF==xI-yI));
};

Alfiere* Alfiere::clone() const
{
    return new Alfiere(*this);
}

std::string Alfiere::getId() const
{
    return "";
}