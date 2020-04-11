 #include "alfiere.h"

Alfiere::Alfiere(Colore _colore):PedinaScacchi(_colore), MovimentoDiagonale(_colore){}

Alfiere* Alfiere::clone() const
{
    return new Alfiere(*this);
}

ID Alfiere::getId() const
{
    return ID('B', getColore());
}
