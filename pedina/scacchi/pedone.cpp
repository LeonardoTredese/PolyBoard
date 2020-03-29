#include "pedone.h"

Pedone::Pedone(ColoreBN _colore, bool _primaMossa)
    : PedinaScacchi(_colore), primaMossa(_primaMossa){}

std::list<Posizione> Pedone::controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat) const
{
    /*if(eat)
    {
        if(getColore() == bianco)
            return yF==yI+1 && (xF==xI+1 || xF==xI-1);
        else
            return yF==yF-1 && (xF==xI+1 || xF==xI-1);
    }
    else
        if(getColore()==bianco) // parte da sotto
            if(primaMossa)
                return yF==yI-1 || yF==yI-2;
            else
                return yF==yI-1;
        else                    // parte da sopra
            if(primaMossa)
                return yF==yI+1 || yF==yI+2;
            else
                return yF==yI+1;
    */
    std::list<Posizione> ris;
    if(eat)
    {
        if((getColore()==bianco && fine.y == inizio.y+1 && (fine.x == inizio.x+1 || fine.x == inizio.x-1))
         || (getColore() == nero && fine.y == fine.y-1 && (fine.x == inizio.x+1 || fine.x == inizio.x-1)))
                ris.push_back(fine);
    }
    else
    {
        if(getColore()==bianco)
        {
            if(primaMossa && (fine.y == inizio.y-1||fine.y==inizio.y-2))
                ris.push_back(fine);
            else if(!primaMossa && fine.y==inizio.y-1)
                ris.push_back(fine);
        }
        else
        {
            if((primaMossa && (fine.y == inizio.y+1 || fine.y == inizio.y+2))
                || (!primaMossa && fine.y == inizio.y+1))
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

void Pedone::fattaPrimaMossa(){ primaMossa=false; }

bool Pedone::getPrimaMossa() const { return primaMossa; }