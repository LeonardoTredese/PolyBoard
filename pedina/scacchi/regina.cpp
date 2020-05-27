#include "regina.h"

Regina::Regina(Colore colore, bool primaMossa)
    : PedinaScacchi(colore, primaMossa), MovimentoCroce(colore, primaMossa), MovimentoDiagonale(colore, primaMossa){}

std::list<Posizione> Regina::controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat) const
{
    std::list<Posizione> ris = MovimentoCroce::controlloMossa(inizio, fine, eat);
    return (!ris.empty()) ? ris : MovimentoDiagonale::controlloMossa(inizio, fine, eat);
}

Regina* Regina::clone() const
{
    return new Regina(*this);
}

ID Regina::getId() const
{
    return ID('Q', getColore(), getPrimaMossa());
}