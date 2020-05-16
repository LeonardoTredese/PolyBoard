#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QString>
#include "view/mainwindow.h"
#include "view/selettore.h"
#include "gioco/gioco.h"
#include "gioco/scacchi.h"
#include "posizione.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    mainWindow *view;
    Gioco *model;
    Posizione *posIniziale, *posFinale;
    void inizializzaPedine(const QString&);
public:
    explicit Controller(QObject *parent = nullptr);

private slots:
    void creaScacchi();
    void raccogliPosizione(Posizione);
};

#endif // CONTROLLER_H
