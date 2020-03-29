#include "scacchi.h"

Scacchi::Scacchi(int width,int height):Gioco(width,height)
{
    // TODO: inserire pedine
}

char Scacchi::tipoGioco() const{return 'c';}

void Scacchi::turno()
{
    int xI, yI, xF, yF;
    std::cout<<"Inserisci posizione pedina da muovere (X,Y): ";
    std::cin>>xI>>yI;
    std::cout<<"Inserisci casella in cui muovere la pedina (X,Y): ";
    std::cin>>xF>>yF;
    // controlloMossa isFree...
    // ritorna orizzontale - diagonale - verticale
    // traiettoriaLibera(p1, p2, direzione)
    // qui so che posso muovere quella pedina
    // la sposto sulla scacchiera senza visualizzare
    // faccio un controllo su scaccoAlRe
    // se ritorna false -> rollback
    // se ritorna true tutto prosegue, mossa valida cambio turno
    
}

// PRE: coloreRe indica il colore del re da controllare
bool Scacchi::scaccoAlRe(ColoreBN coloreRe) const
{
    auto cit=tavolo.begin();
    for(; cit!=tavolo.end(); ++cit) // scorre tutto il tavolo
        if((*cit) && (**cit)->getId() == ID('K', coloreRe))
            break;
    // il re verrà sempre trovato
    Posizione posRe(tavolo.find(*cit));
    
    //for => controllo tutte le pedine del colore avversario
    for(cit=tavolo.begin(); cit!=tavolo.end(); ++cit)
    {
        //le caselle nelle quali le pedine si possono muovere saranno illuminate

        // if(canEat) controlloTraiettoria(posPed,posRe)
        /*
        Controllo mossa ritorna un enum di tipo traiettoria che indica esattamente la traiettoria da 
        controllare per andare da p1 a p2. oppure brute force per tutte le direzioni che la pedina può compiere.
        */
        
    }
}
// POST: ritorna true sse il re di coloreRe è sotto scacco
