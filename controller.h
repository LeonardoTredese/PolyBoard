#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QString>
#include <QJsonObject>  // QT += core ?
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QFile>
#include "view/mainwindow.h"
#include "view/selettore_gioco.h"
#include "gioco/gioco.h"
#include "gioco/scacchi.h"
#include "posizione.h"
#include "tipogioco.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    MainWindow *view;
    Gioco *model;
    Posizione *posIniziale, *posFinale;
    QFile *jsonFile;
    void inizializzaPedine(const TipoGioco&);
    void mossaScacchi(); // per ogni gioco implementato è necessario aggiungere un metodo mossa (ad esempio mossaDama)
    void eliminaPosizioni();
    void importaScacchi();
public:
    explicit Controller(QObject *parent = nullptr);
private slots:
    void resaDichiarata();
    void creaScacchi();
    void raccogliPosizione(Posizione);
    void promozioneScacchi(char);
    void resetPartita();
    void salvaConNome(const QString& filename);
    void salvaPartita();
    void caricaPartita(const QString& filename);
};

#endif // CONTROLLER_H
