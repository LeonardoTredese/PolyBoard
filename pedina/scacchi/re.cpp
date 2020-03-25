#include "re.h"

Re::Re(Colore _colore):PedinaScacchi(_colore){}

bool Re::controlloMossa(short int xI,short int yI,short int xF,short int yF) const{
    return !(xI==xF && yI==yF) && ((xF-1==xI || xF+1==xI || xF==xI) && (yF-1==yI || yF+1==yI || yF==yI));
}

Re* Re::clone() const
{
    return new Re(*this);
}

std::string Re::getId() const
{
    return PedinaScacchi::getId() + "K";
}
