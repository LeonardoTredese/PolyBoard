#include "movimentoDiagonale.h"

MovimentoDiagonale::MovimentoDiagonale(Colore colore, bool primaMossa) : PedinaScacchi(colore, primaMossa) {} 

std::list<Posizione> MovimentoDiagonale::controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat) const
{
    //return (xF+yF==xI+yI || (xF-yF==xI-yI));
    Posizione *direzione=nullptr;
    if(fine.x-fine.y == inizio.x-inizio.y)
    {//diagonale \ inclinata verso sinistra
        if(inizio.y > fine.y)  // alto-sinistra
            direzione = new Posizione(-1,-1);
        else                   // basso-destra
            direzione = new Posizione(1,1);   
    }
    else
        if(fine.x+fine.y == inizio.x+inizio.y)
        { // diagonale / inclinata verso destra
            if(inizio.y > fine.y)   // alto-destra
                direzione = new Posizione(1,-1);
            else                    // basso-sinistra
                direzione = new Posizione(-1,1);    
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