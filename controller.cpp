#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent), view(new mainWindow), model(nullptr)
{
    // il segnale selectedGame(Gioco*) della vista (mainWindow)
    // viene raccolto dallo slot createNewGame(Gioco*) del controller.
    connect(view, SIGNAL(selectedGame(Gioco*)), this, SLOT(createNewGame(Gioco*)));
    view->show();
}

//con questo slot, il controller cancellerà il modello corrente
//e ne creerà uno nuovo tramite il tipo di gioco appena ricevuto
//dalla vista.
void Controller::createNewGame(Gioco* g)
{
    delete model;  // TODO
    model = g;
    // view->addChessboard(..)
    //serve per generare la scacchiera all'interno della mainWindow(vista)
    view->addChessboard(model->getWidth(), model->getHeight());
}
