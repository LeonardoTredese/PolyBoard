#include "pedone.h"

Pedone::Pedone(Colore colore, bool primaMossa)
    : PedinaScacchi(colore, primaMossa){}

std::list<Posizione> Pedone::controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat) const
{
    std::list<Posizione> ris;
    if(eat)
    {
        if((getColore()==bianco && fine.y == inizio.y-1 && (fine.x == inizio.x+1 || fine.x == inizio.x-1))
         || (getColore() == nero && fine.y == inizio.y+1 && (fine.x == inizio.x+1 || fine.x == inizio.x-1)))
                ris.push_back(fine);
    }
    else
    {
        if(getColore()==bianco)
        {
            if(inizio.x == fine.x && ((getPrimaMossa() && (fine.y == inizio.y-1||fine.y==inizio.y-2))
                || (!getPrimaMossa() && fine.y==inizio.y-1)))
                ris.push_back(fine);
        }
        else
        {
            if(inizio.x == fine.x && ((getPrimaMossa() && (fine.y == inizio.y+1 || fine.y == inizio.y+2))
                || (!getPrimaMossa() && fine.y == inizio.y+1)))
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
    return ID('P', getColore(), getPrimaMossa());
}