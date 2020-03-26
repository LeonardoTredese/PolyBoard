#include "scacchi.h"

Scacchi::Scacchi(int width,int height):Gioco(width,height){}

char Scacchi::tipoGioco() const{return 'c';}

void Scacchi::turno()
{
    int xI, yI, xF, yF;
    std::cout<<"Inserisci posizione pedina da muovere (X,Y): ";
    std::cin>>xI>>yI;
    std::cout<<"Inserisci casella in cui muovere la pedina (X,Y): ";
    std::cin>>xF>>yF;
    
}

// PRE: coloreRe indica il colore del re da controllare
bool Scacchi::scaccoAlRe(ColoreBN coloreRe) const
{
    Pedina *re(nullptr);
    for(auto cit=tavolo.begin(); !re && cit!=tavolo.end(); ++cit) // scorre tutto il tavolo
    {
        if(*cit && (*cit)->getId() == ID('K', coloreRe))
            re = *cit;
    }
    Posizione posRe(tavolo.find(re));
    //for => controllo tutte le pedine del colore avversario
    
    for(Pedina* p : tavolo)
    {
        if(p && p->getId().getColore() != coloreRe)
        {
           // bool canEat=p->controlloMossa(posPed,posRe,true)
           // if(canEat) controlloTraiettoria(posPed,posRe)
           
        }
    }
}
// POST: ritorna true sse il re di coloreRe è sotto scacco
