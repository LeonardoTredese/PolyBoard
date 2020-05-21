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
#include <QFileDialog>
#include "selettore_gioco.h"
#include "selettore_promozione_scacchi.h"
#include "chessbutton.h"
#include "../posizione.h"
#include "../pedina/id.h"
#include "../colore.h"
#include "../tipogioco.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    void selezionaPromozioneScacchi();
    MainWindow(QWidget *parent = nullptr);
    void addChessboard(int width, int height);
    void mossaNonValida(); //Visualizza Errore di mossa non valida a schermo
    void aggiungiPedina(const Posizione&, const ID&, const TipoGioco&);
    void pulisciCella(const Posizione&);
    void pulisciFinestra();
    void mostraVincitore(const Colore&);
    void mostraVincitoreResa(const Colore&);
    void setLabelTurno(const Colore&);
    void erroreFile();
protected:
    virtual void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
private:
    int boardWidth, boardHeight;

    QVBoxLayout *mainLayout;
    QGridLayout *gridLayout;
    QLabel *turno;

    QMenu *menuPartita;
    QAction *save, *save_name;

    //aggiunge il menù alla vista
    void addMenu();
    void setStyle();
    void dialogAvviso(const QString&, bool = true);
private slots:
    void nuovaPartita();
    void mostraPareggio();
    void selezionaFileCaricamento();
public slots:
    void selezionaFileSalvataggio();
signals:
    void salvaConNome(const QString&) const;
    void salva() const;
    void carica(const QString&) const;
    void resa() const;
    void terminaPartita() const;
    void nuovaPartitaScacchi() const;
    void casellaSelezionata(Posizione) const;
    void promozioneScacchi(char) const;
    void resetFinestra() const;
    void resaDichiarata() const;
};

#endif // MAINWINDOW_H
