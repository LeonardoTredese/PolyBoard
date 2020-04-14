#include "re.h"

Re::Re(Colore _colore, bool _primaMossa):PedinaScacchi(_colore), primaMossa(_primaMossa){}

std::list<Posizione> Re::controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat) const{
    std::list<Posizione> ris;
    if(inizio != fine && ((fine.x-1 == inizio.x || fine.x+1 == inizio.x || fine.x == inizio.x) && 
      (fine.y-1==inizio.y || fine.y+1==inizio.y || fine.y==inizio.y)))  // TODO: rivedere if
        ris.push_back(fine);
    return ris;
}

Re* Re::clone() const
{
    return new Re(*this);
}

ID Re::getId() const
{
    return ID('K', getColore());
}

void Re::pedinaMossa() { primaMossa = false; }