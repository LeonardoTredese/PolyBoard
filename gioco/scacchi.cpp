#include "scacchi.h"

Scacchi::Scacchi(int width,int height):Gioco(width, height, bianco)
{
    // TODO: inserire pedine
}

char Scacchi::tipoGioco() const{return 'c';}

bool Scacchi::turno(const Posizione& posIniziale,const Posizione& posFinale)
{
    if(!tavolo.isInBound(posFinale))
        return false;
    try{
        if(tavolo.selectElement(posIniziale)->getColore() != giocatore_corrente)
            return false;
    }
    catch(ErroreScacchiera(ELEMENT_NOT_FOUND))
    {
        return false;
    }
    // qui sappiamo per certo che le due posizioni sono in bound e che la pedina in posIniziale è del giocatore corrente
    SmartP& sp = tavolo.selectElement(posIniziale);
    bool eat = !tavolo.isFree(posFinale);
    std::list<Posizione> traiettoria = sp->controlloMossa(posIniziale, posIniziale, eat);
        // È ARRIVATA LA GENIALATA, STOP ADNAN
    
    /*
    * \1 controllo colore posI, se != giocatore_corrente throw o altro
    * \2 controlloMossa da posI a posF sia con true che con false / oppure typeid su pedone
    * 3 controllo se la traiettoria è libera
    * 4 muovo la pedina con moveForce se la posizione di arrivo è occupata da una pedina avversaria oppure vuota
    * 5 altrimenti se occupata da un amico non eseguo la mossa
    * 6 
    */
}

// PRE: coloreRe indica il colore del re da controllare
bool Scacchi::scaccoAlRe(Colore coloreRe) const
{
    auto cit=tavolo.begin();
    for(; cit!=tavolo.end(); ++cit) // scorre tutto il tavolo
        if((*cit) && (**cit)->getId() == ID('K', coloreRe))
            break;
    // il re verrà sempre trovato
    Posizione posRe(tavolo.find(*cit));
    
    // for => controllo tutte le pedine del colore avversario
    for(cit=tavolo.begin(); cit!=tavolo.end(); ++cit)
        if((*cit) && (**cit)->getColore() != coloreRe &&
         tavolo.traiettoriaLibera((**cit)->controlloMossa(tavolo.find(*cit), posRe, true)))
            return true;  // se la posizione non è una pedina vuota, ed è di colore diverso dal Re 
                         // e la traiettoria tra la pedina e il Re è libera
    return false;
}
// POST: ritorna true sse il re di coloreRe è sotto scacco
