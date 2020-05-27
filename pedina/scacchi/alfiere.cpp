 #include "alfiere.h"

Alfiere::Alfiere(Colore colore, bool primaMossa) : PedinaScacchi(colore, primaMossa), MovimentoDiagonale(colore, primaMossa) {}

Alfiere* Alfiere::clone() const
{
    return new Alfiere(*this);
}

ID Alfiere::getId() const
{
    return ID('B', getColore(), getPrimaMossa());
}
