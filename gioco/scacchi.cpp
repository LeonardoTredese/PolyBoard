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
        tavolo.insert(pedBianco, Posizione(x,6)); // per i bianchi la y=6
        tavolo.insert(pedNero, Posizione(x,1)); // per i neri la y=1
    }

    // inseriamo pedine bianche
    tavolo.insert(torBianco, Posizione(0,7));
    tavolo.insert(cavBianco, Posizione(1,7));
    tavolo.insert(alfBianco, Posizione(2,7));
    tavolo.insert(reBianco,  Posizione(3,7));
    tavolo.insert(regBianco, Posizione(4,7));
    tavolo.insert(alfBianco, Posizione(5,7));
    tavolo.insert(cavBianco, Posizione(6,7));
    tavolo.insert(torBianco, Posizione(7,7));

    // inseriamo pedine nere
    tavolo.insert(torNero, Posizione(0,0));
    tavolo.insert(cavNero, Posizione(1,0));
    tavolo.insert(alfNero, Posizione(2,0));
    tavolo.insert(regNero, Posizione(3,0));
    tavolo.insert(reNero,  Posizione(4,0));
    tavolo.insert(alfNero, Posizione(5,0));
    tavolo.insert(cavNero, Posizione(6,0));
    tavolo.insert(torNero, Posizione(7,0));
}

char Scacchi::tipoGioco() const {return 'c';}

bool Scacchi::mossa(const Posizione& posIniziale, const Posizione& posFinale)
{
    if(!tavolo.isInBound(posFinale)){
        cout << "## Out of bound ##" << endl;
        return false;
    }
    Pedina* pedinaSel = tavolo[posIniziale]; // pedina da muovere
    if(!pedinaSel || pedinaSel->getColore() != giocatore_corrente)
    {
        cout << "## posIniziale non valida ##" << endl;
        return false;
    }
    // qui sappiamo per certo che le due posizioni sono in bound e che la pedina in posIniziale è del giocatore corrente
    if(!tavolo.isFree(posFinale) && pedinaSel->getColore() == tavolo[posFinale]->getColore()) // non posso mangiare pedine amiche
    {
        cout<<"## Mangio pedina amica ##"<<endl;
        return false;
    }
    bool eat = !tavolo.isFree(posFinale);
    std::list<Posizione> traiettoria = pedinaSel->controlloMossa(posIniziale, posFinale, eat);
    if(!tavolo.traiettoriaLibera(traiettoria))
    {
        cout<<"## Traiettoria vuota/Traiettoria non libera ##"<<endl;
        return false;
    }
    //per effettuare il rollback devo salvarmi la pedina, nel caso essa venga mangiata
    bool backup = !tavolo.isFree(posFinale);
    Pedina* backupFine(nullptr);
    if(backup)
        backupFine = tavolo[posFinale]->clone();
    tavolo.move(posIniziale, posFinale);
    if(scaccoAlRe(pedinaSel->getColore()))
    {
        tavolo.move(posFinale, posIniziale);
        cout<<"##### Sono in scacco al Re ######"<<endl;
        if(backup)
            tavolo.insert(*backupFine, posFinale);
        delete backupFine;
        return false;
    }
    
    if( posFinale.y==0 || posFinale.y==height-1 ) // trasformazione pedone quando arriva dall'avversario
    {
        Pedone* p = dynamic_cast<Pedone*>(pedinaSel);
        if(p)
        {
            cout << "## Trasformazione pedone ##" << endl;
            char scelta;
            bool sceltaCorretta;
            tavolo.remove(posFinale);
            do
            {
                sceltaCorretta = true;
                cout << "Scegli la pedina da evocare: (Q/N/B/R) ";
                std::cin >> scelta;
                switch (scelta)
                {
                case 'Q': 
                    tavolo.insert(Regina(giocatore_corrente), posFinale);
                    break;
                
                case 'N':   
                    tavolo.insert(Cavallo(giocatore_corrente), posFinale);
                    break;
                
                case 'B': 
                    tavolo.insert(Alfiere(giocatore_corrente), posFinale);
                    break;
                        
                case 'R':   
                    tavolo.insert(Torre(giocatore_corrente), posFinale);
                    break;
                        
                default:
                    cout << "SCELTA NON VALIDA" << endl;
                    sceltaCorretta = false;
                    break;
                }
            } while(!sceltaCorretta);
            pedinaSel = tavolo[posFinale];
        }   
    }
    pedinaSel->pedinaMossa();
    return true;
}

// PRE: coloreRe indica il colore del re da controllare
bool Scacchi::scaccoAlRe(Colore coloreRe) const
{
    auto cit=tavolo.begin();
    for(; cit!=tavolo.end(); ++cit) // scorre tutto il tavolo
        if((*cit) && (*cit)->getId() == ID('K', coloreRe))
            break;
    // il re verrà sempre trovato
    Posizione posRe(tavolo.find(*cit));
    
    // for => controllo tutte le pedine del colore avversario
    for(cit=tavolo.begin(); cit!=tavolo.end(); ++cit)
        if((*cit) && (*cit)->getColore() != coloreRe &&
         tavolo.traiettoriaLibera((*cit)->controlloMossa(tavolo.find(*cit), posRe, true)))
         {
            //ID id ((*cit)->getId());
            //cout << id.getTipo() << id.getColore() << endl;
            return true;  // se la posizione non è una pedina vuota, ed è di colore diverso dal Re 
                         // e la traiettoria tra la pedina e il Re è libera
         }
    return false;
}
// POST: ritorna true sse il re di coloreRe è sotto scacco

bool Scacchi::scaccoMatto(Colore coloreRe) const // TODO: ottimizzabile? sì(difficile peggiorare) sarà ottimizzata? absolutely no prenderai 4/30? absolutely yes
{
    Scacchi backup(*this);
    for(int y1=0; y1<height; ++y1)
        for(int x1=0; x1<width; ++x1)
        {
            Pedina* p = backup.tavolo[Posizione(x1,y1)]; 
            if(p && p->getColore() == coloreRe)
            {
                Posizione pI(x1, y1);
                for(int y2=0; y2<height; ++y2)
                    for(int x2=0; x2<width; ++x2)
                        if(backup.mossa(pI, Posizione(x2, y2)))
                            return false;
            }
        }
    return true;
}
bool Scacchi::controlloVincitore() const
{
    Colore avversario = (giocatore_corrente == bianco) ? nero : bianco;
    if(scaccoAlRe(avversario))
        return scaccoMatto(avversario);
    else
        return false;
}
void Scacchi::cambioTurno()
{
    giocatore_corrente = (giocatore_corrente == bianco) ? nero : bianco;
}
