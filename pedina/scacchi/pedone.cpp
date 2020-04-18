#include "pedone.h"

Pedone::Pedone(Colore _colore, bool _primaMossa)
    : PedinaScacchi(_colore), primaMossa(_primaMossa){}

std::list<Posizione> Pedone::controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat) const
{
    std::list<Posizione> ris;
    if(eat)
    {
        if((getColore()==bianco && fine.y == inizio.y-1 && (fine.x == inizio.x+1 || fine.x == inizio.x-1))
         || (getColore() == nero && fine.y == fine.y+1 && (fine.x == inizio.x+1 || fine.x == inizio.x-1)))
                ris.push_back(fine);
    }
    else
    {
        if(getColore()==bianco)
        {
            if(inizio.x == fine.x && ((primaMossa && (fine.y == inizio.y-1||fine.y==inizio.y-2))
                || (!primaMossa && fine.y==inizio.y-1)))
                ris.push_back(fine);
        }
        else
        {
            if(inizio.x == fine.x && ((primaMossa && (fine.y == inizio.y+1 || fine.y == inizio.y+2))
                || (!primaMossa && fine.y == inizio.y+1)))
                ris.push_back(fine);
        }    
    }
    return ris;
}

Pedone* Pedone::clone() const
{
    return new Pedone(*this);
}

ID Pedone::getId() const
{
    return ID('P',getColore());
}

void Pedone::pedinaMossa(){ if(primaMossa) primaMossa=false; }