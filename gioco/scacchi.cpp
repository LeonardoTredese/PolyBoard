#include "scacchi.h"
#define width 8
#define height 8

Scacchi::Scacchi():Gioco(width, height, bianco)
{
    Pedone pedBianco(bianco), pedNero(nero);
    Alfiere alfBianco(bianco), alfNero(nero);
    Torre torBianco(bianco),torNero(nero);
    Re reBianco(bianco), reNero(nero);
    Regina regBianco(bianco), regNero(nero);
    Cavallo cavBianco(bianco),cavNero(nero);

    // mettiamo pedoni bianchi e poi neri
    for(int x=0; x<width; ++x)
    {
        tavolo.insert(&pedBianco, Posizione(x,6)); // per i bianchi la y=6
        tavolo.insert(&pedNero, Posizione(x,1)); // per i neri la y=1
    }

    // inseriamo pedine bianche
    tavolo.insert(&torBianco, Posizione(0,7));
    tavolo.insert(&cavBianco, Posizione(1,7));
    tavolo.insert(&alfBianco, Posizione(2,7));
    tavolo.insert(&reBianco,  Posizione(3,7));
    tavolo.insert(&regBianco, Posizione(4,7));
    tavolo.insert(&alfBianco, Posizione(5,7));
    tavolo.insert(&cavBianco, Posizione(6,7));
    tavolo.insert(&torBianco, Posizione(7,7));

    // inseriamo pedine nere
    tavolo.insert(&torNero, Posizione(0,0));
    tavolo.insert(&cavNero, Posizione(1,0));
    tavolo.insert(&alfNero, Posizione(2,0));
    tavolo.insert(&regNero, Posizione(3,0));
    tavolo.insert(&reNero,  Posizione(4,0));
    tavolo.insert(&alfNero, Posizione(5,0));
    tavolo.insert(&cavNero, Posizione(6,0));
    tavolo.insert(&torNero, Posizione(7,0));
}

char Scacchi::tipoGioco() const {return 'c';}

bool Scacchi::mossa(const Posizione& posIniziale,const Posizione& posFinale)
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
    SmartP& sp = tavolo.selectElement(posIniziale); // mia pedina
    if(!tavolo.isFree(posFinale) && sp->getColore() == tavolo.selectElement(posFinale)->getColore()) // non posso mangiare pedine amiche
        return false;
    bool eat = !tavolo.isFree(posFinale);
    std::list<Posizione> traiettoria = sp->controlloMossa(posIniziale, posFinale, eat);
    if(traiettoria.empty() || !tavolo.traiettoriaLibera(traiettoria))
        return false;
    //per effettuare il rollback devo salvarmi la pedina, nel caso essa venga mangiata
    bool backup = !tavolo.isFree(posFinale);
    SmartP backupFine;
    if(backup)
        backupFine = tavolo.selectElement(posFinale); // clone(), copia profonda
    tavolo.moveForce(posIniziale, posFinale);
    if(scaccoAlRe(sp->getColore()))
    {
        tavolo.moveForce(posFinale, posIniziale);
        if(backup)
            tavolo.insert(backupFine, posFinale);
        return false;
    }
    if(Pedone* p = dynamic_cast<Pedone*>(&(*sp))) // TODO: è accettabile il dynamic cast su pedone??? spoiler: no
        p->fattaPrimaMossa();
    return true;
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

bool Scacchi::scaccoMatto(Colore coloreRe) const // TODO: ottimizzabile? sì(difficile peggiorare) sarà ottimizzata? absolutely no prenderai 4/30? absolutely yes
{
    Scacchi backup(*this);
    for(int y1=0; y1<height; ++y1)
        for(int x1=0; x1<width; ++x1)
        {
            SmartP* p;
            try
            {
                p = &(backup.tavolo.selectElement(Posizione(x1,y1))); 
            }
            catch(ErroreScacchiera(ELEMENT_NOT_FOUND))
            {
                continue;
                // se la casella x,y è vuota non faccio nulla
            }
            if((*p)->getColore() == coloreRe)
            {
                Posizione pI(x1, y1);
                for(int y2=0; y2<height; ++y2)
                    for(int x2=0; x2<width; ++x2)
                        if(backup.mossa(pI, Posizione(x2, y2)))
                        {
                            return false;
                        }
            }
        }
        return true;
}
bool Scacchi::controlloVincitore() const
{
    return scaccoMatto((giocatore_corrente == bianco) ? nero : bianco);
}
void Scacchi::cambioTurno()
{
    giocatore_corrente = (giocatore_corrente == bianco) ? nero : bianco;
}