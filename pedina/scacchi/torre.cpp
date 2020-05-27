#include "torre.h"

Torre::Torre(Colore colore, bool primaMossa): PedinaScacchi(colore, primaMossa), MovimentoCroce(colore, primaMossa) {}

Torre* Torre::clone() const
{
    return new Torre(*this);
}

ID Torre::getId() const
{
    return ID('R', getColore(), getPrimaMossa());
}