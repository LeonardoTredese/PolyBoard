#include "controller.h"

//Il controller itera sulla schacchiera e aggiorna di conseguenza la vista
Controller::Controller(QObject *parent)
 : QObject(parent), view(new MainWindow), model(nullptr),
  posIniziale(nullptr), posFinale(nullptr), fileCaricato("")
{
    // il segnale selectedGame(Gioco*) della vista (MainWindow)
    // viene raccolto dallo slot createNewGame(Gioco*) del controller.
    connect(view, SIGNAL(nuovaPartitaScacchi()), this, SLOT(creaScacchi()));
    connect(view, SIGNAL(casellaSelezionata(Posizione)), this, SLOT(raccogliPosizione(Posizione)));
    connect(view, SIGNAL(promozioneScacchi(char)),this,SLOT(promozioneScacchi(char)));
    connect(view, SIGNAL(resetFinestra()), this, SLOT(resetPartita()));
    connect(view, SIGNAL(terminaPartita()), this, SLOT(resetPartita()));
    connect(view, SIGNAL(resa()),this,SLOT(resaDichiarata()));
    connect(view, SIGNAL(salvaConNome(const QString&)), this, SLOT(salvaConNome(const QString&)));
    connect(view, SIGNAL(salva()), this, SLOT(salvaPartita()));
    connect(view, SIGNAL(carica(const QString&)), this, SLOT(caricaPartita(const QString&)));
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
    view->setLabelTurno(model->getGiocatoreCorrente());
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
    {
        if(!(model->isEmpty(pos_))) // scelgo una casella non vuota come pos iniziale
            posIniziale = new Posizione(pos_);
    }
    else 
    {
        if(!posFinale)
        {
            posFinale = new Posizione(pos_);
            switch (model->tipoGioco())
            {
                case chess: 
                    mossaScacchi();  //  le posizioni devono essere eliminate qua dentro
                    break;
                default:
                    eliminaPosizioni();
            }
        }
    }
}

void Controller::mossaScacchi()
{
    Scacchi* modelScacchi = static_cast<Scacchi*>(model);
    bool ris = modelScacchi->mossa(*posIniziale, *posFinale);
    if(ris) // mossa andata a buon fine, pedine mosse
    {
        if(modelScacchi->verificaPromozionePedone(*posFinale))
        {
            view->selezionaPromozioneScacchi();
            return;
        }
        inizializzaPedine(modelScacchi->tipoGioco());
        if(modelScacchi->controlloVincitore())
        {
            view->mostraVincitore(modelScacchi->getGiocatoreCorrente());
            return;
        }
        modelScacchi->cambioTurno();
        view->setLabelTurno(modelScacchi->getGiocatoreCorrente());
    }
    else  // mossa non valida
        view->mossaNonValida();
    eliminaPosizioni();
}

void Controller::promozioneScacchi(char pedinaSel)
{
    Scacchi* modelScacchi = static_cast<Scacchi*>(model);
    modelScacchi->promozionePedone(pedinaSel, *posFinale);
    inizializzaPedine(modelScacchi->tipoGioco());
    modelScacchi->cambioTurno();
    view->setLabelTurno(modelScacchi->getGiocatoreCorrente());
    if(modelScacchi->controlloVincitore())
    {
        view->mostraVincitore(modelScacchi->getGiocatoreCorrente());
        return;
    }
    eliminaPosizioni();
    view->setEnabled(true);
}

void Controller::eliminaPosizioni()
{
    delete posFinale;
    delete posIniziale;
    posIniziale = posFinale = nullptr;
}

void Controller::resetPartita()
{
    delete model;
    model = nullptr;
    eliminaPosizioni();
    view->pulisciFinestra();
    view->setEnabled(true);
}

void Controller::resaDichiarata()
{
    model->cambioTurno();
    view->setLabelTurno(model->getGiocatoreCorrente());
    view->mostraVincitoreResa(model->getGiocatoreCorrente());
}

void Controller::salvaConNome(const QString& filename)
{
    // TODO: invocare solo se model != nullptr
    //creo il file .json
    QJsonObject json;
    int i = 0;
    json.insert("gioco", model->tipoGioco());
    json.insert("turno", model->getGiocatoreCorrente());
    for(int y=0; y < model->getHeight(); y++)
        for(int x=0; x < model->getWidth(); x++)
        {
            ID *current = model->getIdPedina(Posizione(x,y));
            if(current)
            {
                QJsonArray *id = new QJsonArray({current->getTipo(), current->getColore(), current->getPrimaMossa()}), *pos = new QJsonArray({x, y});
                json.insert(QString::number(i++), QJsonArray({*id, *pos}));
            }
        }
    fileCaricato = filename;
    QFile jsonFile(fileCaricato);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(QJsonDocument(json).toJson());
}

void Controller::salvaPartita()
{
    QFile jsonFile(fileCaricato);
    if(jsonFile.exists())
        salvaConNome(jsonFile.fileName());
    else
        view->selezionaFileSalvataggio();
}

void Controller::caricaPartita(const QString& filename)
{
    //delete fileCaricato;
    fileCaricato = filename;
    QFile jsonFile (fileCaricato);
    if(jsonFile.exists())
    {
        jsonFile.open(QFile::ReadOnly);
        QJsonObject json = QJsonDocument::fromJson(jsonFile.readAll()).object();
        
        if(json.contains("gioco") && json.contains("turno"))
        {
            // import gioco
            switch(TipoGioco(json["gioco"].toInt()))
            {
                case chess:
                    delete model;
                    model = new Scacchi(Colore(json["turno"].toInt()), false);
                    break;
                // altri giochi
            }
            
            // import pedine
            for(auto it = json.begin(); it != json.end(); it++)
                if(it.key() != "gioco" && it.key() != "turno")
                {
                    QJsonArray arrayId = it.value().toArray()[0].toArray(), arrayPos = it.value().toArray()[1].toArray();
                    ID id(static_cast<char>(arrayId[0].toInt()), Colore(arrayId[1].toInt()), arrayId[2].toBool());
                    Posizione pos(arrayPos[0].toInt(), arrayPos[1].toInt());
                    model->inserisciPedina(pos, id);
                }
            
            view->addChessboard(model->getWidth(), model->getHeight());  // scacchiera vuota
            inizializzaPedine(model->tipoGioco());  // sincronizzazione della view con il model
            view->setLabelTurno(model->getGiocatoreCorrente());
        }
        else
        {
            fileCaricato = "";
            view->erroreFile();
        }
    }
    else
    {
        fileCaricato = "";  // file inesistente
        view->erroreFile();
    }

}

/*

{
    1: [['k',2], [12,5]]
    2: [ID, Pos]
}

*/
