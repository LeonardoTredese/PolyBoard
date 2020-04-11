#include "torre.h"

Torre::Torre(Colore _colore): PedinaScacchi(_colore), MovimentoCroce(_colore) {}

Torre* Torre::clone() const
{
    return new Torre(*this);
}

ID Torre::getId() const
{
    return ID('R', getColore());
}
