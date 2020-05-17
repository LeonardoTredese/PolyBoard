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
    inizializzaPedine(model->tipoGioco());
}

void Controller::inizializzaPedine(const TipoGioco& tipoGioco)
{
    ID* idPedina(nullptr);
    for(int y=0; y < model->getHeight(); y++)
        for(int x=0; x < model->getWidth(); x++)
        {
            idPedina = model->getIdPedina(Posizione(x,y));
            if(idPedina)
                view->aggiungiPedina(Posizione(x,y), *idPedina, tipoGioco);
            else
                view->pulisciCella(Posizione(x,y));
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
            switch (model->tipoGioco())
            {
                case chess: 
                    mossaScacchi(); 
                    break;
                default: 

                    break;
            }
            delete posFinale;
            delete posIniziale;
            posIniziale = posFinale = nullptr;
        }
        else
            abort(); // TODO: togliere, solo per test
}

void Controller::mossaScacchi()
{
    Scacchi* modelScacchi = static_cast<Scacchi*>(model);
    bool ris = modelScacchi->mossa(*posIniziale, *posFinale);
    if(ris) // mossa andata a buon fine, pedine mosse
    {
        if(modelScacchi->verificaPromozionePedone(*posFinale))
        {
            //view->selezionaPromozioneScacchi();
            modelScacchi->promozionePedone('Q', *posFinale); 
        }
        inizializzaPedine(modelScacchi->tipoGioco());
        modelScacchi->cambioTurno();
        // TODO: controllo vincitore
    }
    else  // mossa non valida
        view->mossaNonValida();
}

void Controller::promozioneScacchi(char c)
{}