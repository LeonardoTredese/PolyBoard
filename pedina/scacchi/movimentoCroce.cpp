#include "movimentoCroce.h"


MovimentoCroce::MovimentoCroce(Colore colore, bool primaMossa) : PedinaScacchi(colore, primaMossa){}

std::list<Posizione> MovimentoCroce::controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat) const
{
    Posizione *direzione(nullptr);
    if(inizio.x == fine.x)
    {
        if(inizio.y > fine.y)
            direzione = new Posizione(0,-1); // movimento in su
        else
            direzione = new Posizione(0,1);  //movimento in giù
    }
    else if(inizio.y == fine.y)
    {
        if(inizio.x > fine.x)
            direzione = new Posizione(-1,0); //movimento a sinistra
        else
            direzione = new Posizione(1,0);   // movimento a destra
    }
    std::list<Posizione> ris;
    if(direzione)
    {
        Posizione pos_attuale(inizio);
        for(int i=0; pos_attuale != fine; ++i)
        {
            pos_attuale = inizio + (*direzione)*(i+1);
            ris.push_back(pos_attuale);
        }
    }
    delete direzione;
    return ris;
}
