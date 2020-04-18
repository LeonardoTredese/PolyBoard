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
    tavolo.insert(regBianco, Posizione(3,7));
    tavolo.insert(reBianco,  Posizione(4,7));
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
        //cout << "## Out of bound ##" << endl;
        return false;
    }
    Pedina* pedinaSel = tavolo[posIniziale]; // pedina da muovere
    if(!pedinaSel || pedinaSel->getColore() != giocatore_corrente)
    {
        //cout << "## posIniziale non valida ##" << endl;
        return false;
    }
    // qui sappiamo per certo che le due posizioni sono in bound e che la pedina in posIniziale è del giocatore corrente
    
    if(!arrocco(posIniziale, posFinale))
    {
        if(!tavolo.isFree(posFinale) && pedinaSel->getColore() == tavolo[posFinale]->getColore()) // non posso mangiare pedine amiche
        {
            //cout<<"## Mangio pedina amica ##"<<endl;
            return false;
        }
        bool eat = !tavolo.isFree(posFinale);
        std::list<Posizione> traiettoria = pedinaSel->controlloMossa(posIniziale, posFinale, eat);
        if(!tavolo.traiettoriaLibera(traiettoria))
        {
            //cout<<"## Traiettoria vuota/Traiettoria non libera ##"<<endl;
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
            //cout<<"##### Sono in scacco al Re ######"<<endl;
            if(backup)
                tavolo.insert(*backupFine, posFinale);
            delete backupFine;
            return false;
        }
        
        //TODO: Metodo per la promozione del pedone a parte
        if( posFinale.y==0 || posFinale.y==height-1 ) // trasformazione pedone quando arriva dall'avversario
        {
            Pedone* p = dynamic_cast<Pedone*>(pedinaSel);
            if(p)
            {
                //cout << "## Trasformazione pedone ##" << endl;
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

bool Scacchi::scaccoMatto(Colore coloreRe) const
{
    Scacchi backup(*this);
    backup.giocatore_corrente = coloreRe;//switcho al colore avversario 
    auto cit=tavolo.begin();
    for(; cit!=tavolo.end(); ++cit) // scorre tutto il tavolo
        if((*cit) && (*cit)->getId() == ID('K', coloreRe))
            break;
    // il re verrà sempre trovato
    //prima di fare brute force su tutte le posizioni possibili, provo a spostare il re
    Posizione posRe(tavolo.find(*cit));
    for(int i=-1; i < 2; i++)
        for(int j=-1; j < 2; j++)
            if(backup.mossa(posRe, Posizione(posRe.x+j,posRe.y+i)))
                return false;
    //altrimenti provo con tutte le posizioni possibili eccetto il re che è già stato verificato   
    for(int y1=0; y1<height; ++y1)
        for(int x1=0; x1<width; ++x1)
        {
            Pedina* p = backup.tavolo[Posizione(x1,y1)]; 
            if(p && p->getColore() == coloreRe)
            {
                Posizione pI(x1, y1);
                if(pI != posRe)
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

/* ARROCCO:
* 1 - verifico se la pedina che vuole muoversi è il re
*     (non con dynamic cast, verificando se primamossa=true in posRe)
* 2 - se la posFinale è una delle due caselle designate. 
*     per l'arrocco verifico le condizioni di primamossa della casella in cui è la torre senza dynamic cast
* 3 - se tutto è verificato, provo a muovere il re una casella per volta, verificando che non sia sotto scacco 
*     ad ogni mossa, compresa quella iniziale
*     3.1 - in caso una mossa risulti sotto scacco si effettua il rollback alla posizione inziale del re
*     3.2 - se tutte le condizioni sono verificate, e il re si è mosso correttamente, sposto la torre nella posizione designata.
*/

// PRE: la posizione iniziale e quella finale indicano un tentativo di arrocco del re Colore re
bool Scacchi::arrocco(const Posizione& re, const Posizione& finale)
{
    Re* r = dynamic_cast<Re*>(tavolo[re]);
    if (!r || !r->getPrimaMossa())
        return false;
    //controllo posizione torre
    Torre* t;
    if(finale==re+Posizione(2,0))
    {//torre destra
        t=dynamic_cast<Torre*>(tavolo[re+Posizione(3,0)]);
    }
    else if (finale == re + Posizione(-2,0))
    {//torre sinistra
        t = dynamic_cast<Torre*>(tavolo[re + Posizione(-4,0)]);
    }
    
    if(!t || !t->getPrimaMossa())
        return false;
        
    // assert( l'arrocco è possibile, il re può arroccare con la relativa torre )
    bool canMove(true);
    //qualunque colore sia il re si sposta a sinistra o destra
    int c = (finale == re + Posizione(2,0)) ? 1 : -1; // indica se stai andando a destra (1) o a sinistra (-1)
    int i=0;
    for(; canMove && i<2; i++)
    {
        if(tavolo.move(re+(Posizione(c,0)*i), re+(Posizione(c,0)*(i+1)), false))  //sposto il re di una mossa per volta
           canMove = !scaccoAlRe(tavolo[re+(Posizione(c,0)*(i+1))]->getColore());
        else
            canMove = false;
    }
    // se canMove è a true significa che li il re può stare, quindi muove la torre e termina
    if(canMove)
    {
        tavolo.move(c==1 ? re+Posizione(3,0) : re+Posizione(-4,0) , re+Posizione(c,0));
        r->pedinaMossa();
        t->pedinaMossa();
        return true;
    }
    else
    {//arrocco non possibile effettuo il rollback della posizione
        if(i > 0)
            tavolo.move(re+Posizione(c*i,0), re);
        return false;
    }
}
// POST: se ci sono le condizioni per l'arrocco lo fa e ritorna true,
// altrimenti non deve modificare nulla e ritornare false