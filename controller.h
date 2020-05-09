#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "view/mainwindow.h"
#include "view/selettore.h"
#include "gioco/gioco.h"
#include "gioco/scacchi.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    mainWindow *view;
    Gioco *model;
public:
    explicit Controller(QObject *parent = nullptr);

private slots:
    void createNewGame(Gioco*);
};

#endif // CONTROLLER_H
