#include "controller.h"
//Il controller itera sulla schacchiera e aggiorna di conseguenza la vista
Controller::Controller(QObject *parent) : QObject(parent), view(new mainWindow), model(nullptr), posIniziale(nullptr), posFinale(nullptr)
{
    // il segnale selectedGame(Gioco*) della vista (mainWindow)
    // viene raccolto dallo slot createNewGame(Gioco*) del controller.
    connect(view, SIGNAL(nuovaPartitaScacchi()), this, SLOT(creaScacchi()));
    connect(view, SIGNAL(casellaSelezionata(Posizione)), this, SLOT(raccogliPosizione(Posizione)));
    view->show();
}

//con questo slot, il controller cancellerà il modello corrente
//e ne creerà uno nuovo tramite il tipo di gioco appena ricevuto
//dalla vista.
void Controller::creaScacchi()
{
    delete model;  // TODO non basta 
    model = new Scacchi();
    view->addChessboard(model->getWidth(), model->getHeight()); // aggiunge scacchiera vuota
    //per inizializzare la Scacchiera, itero su di essa e invoco il metodo aggiungiPedina() della view
    inizializzaPedine("chess");
}

void Controller::inizializzaPedine(const QString& tipoGioco)
{
    for(int y=0; y < model->getHeight(); y++)
        for(int x=0; x < model->getWidth(); x++)
        {
            ID* idPedina = model->getIdPedina(Posizione(x,y));
            if(idPedina)
                view->aggiungiPedina(Posizione(x,y), *idPedina, tipoGioco);
        }
}

void Controller::raccogliPosizione(Posizione pos_)
{
    if(!posIniziale)
        posIniziale = new Posizione(pos_);
    else
        if(!posFinale)
        {
            posFinale = new Posizione(pos_);
            bool ris = model->mossa(*posIniziale, *posFinale);  // TODO
            if(ris) // mossa andata a buon fine, pedine mosse
            {
                view->updateBoard(*posIniziale, *posFinale);
                model->cambioTurno();
                // TODO controllo vincitore
            }
            else  // mossa non valida
                view->mossaNonValida();
            delete posFinale;
            delete posIniziale;
            posIniziale = posFinale = nullptr;
        }
        else
            abort(); // TODO: togliere, solo per test
}
