#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFile>
#include <QResizeEvent>
#include <QSize>
#include <QApplication>
#include <QScreen>
#include <QDialog>
#include <QLabel>
#include <QPixmap>
#include <QIcon>
#include <QString>
#include <QSizePolicy>
#include <QResizeEvent>
#include "selettore_gioco.h"
#include "selettore_promozione_scacchi.h"
#include "chessbutton.h"
#include "../posizione.h"
#include "../pedina/id.h"
#include "../colore.h"
#include "../tipogioco.h"

class mainWindow : public QWidget
{
    Q_OBJECT
public:
    void selezionaPromozioneScacchi();
    mainWindow(QWidget *parent = nullptr);
    void addChessboard(int width, int height);
    void mossaNonValida(); //Visualizza Errore di mossa non valida a schermo
    void aggiungiPedina(const Posizione&, const ID&, const TipoGioco&);
    void pulisciCella(const Posizione&);
protected:
    virtual void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
private:
    QVBoxLayout *mainLayout;
    QGridLayout *gridLayout;
    int boardWidth, boardHeight;
    //aggiunge il menù alla vista
    void addMenu();
    void setStyle();
    void cleanGrid();
private slots:
    void nuovaPartita() const;
signals:
    void nuovaPartitaScacchi() const;
    void casellaSelezionata(Posizione) const;
    void promozioneScacchi(char) const;
};

#endif // MAINWINDOW_H
