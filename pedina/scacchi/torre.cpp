#include "torre.h"

Torre::Torre(Colore _colore, bool _primaMossa): PedinaScacchi(_colore), MovimentoCroce(_colore), primaMossa(_primaMossa) {}

Torre* Torre::clone() const
{
    return new Torre(*this);
}

ID Torre::getId() const
{
    return ID('R', getColore(), primaMossa);
}

void Torre::pedinaMossa() { primaMossa = false; }

bool Torre::getPrimaMossa() const { return primaMossa; }