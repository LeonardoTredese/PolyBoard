#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent), view(new mainWindow), model(nullptr)
{
    connect(view, SIGNAL(selectedGame(Gioco*)), this, SLOT(createNewGame(Gioco*)));
    view->show();
}

void Controller::createNewGame(Gioco* g)
{
    delete model;  // TODO
    model = g;
    view->addChessboard(model->getWidth(), model->getHeight());
}
