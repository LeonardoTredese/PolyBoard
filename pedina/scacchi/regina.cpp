#include "regina.h"

Regina::Regina(Colore _colore)
    : PedinaScacchi(_colore), Torre(_colore), Alfiere(_colore){}

std::list<Posizione> Regina::controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const
{
    std::list<Posizione> ris = Torre::controlloMossa(inizio, fine, eat);
    return (!ris.empty()) ? ris : Alfiere::controlloMossa(inizio, fine, eat);
}

Regina* Regina::clone() const
{
    return new Regina(*this);
}

ID Regina::getId() const
{
    return ID('Q', getColore());
}