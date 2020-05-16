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
#include "selettore.h"
#include "chessbutton.h"
#include "../posizione.h"
#include "../pedina/id.h"
#include "../colore.h"

class mainWindow : public QWidget
{
    Q_OBJECT
public:
    mainWindow(QWidget *parent = nullptr);
    void addChessboard(int width, int height);
    void mossaNonValida(); //Visualizza Errore di mossa non valida a schermo
    void updateBoard(const Posizione& iniziale, const Posizione& finale);
    void aggiungiPedina(const Posizione&, const ID&, const QString&);
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
    void nuovaPartita();
signals:
    void nuovaPartitaScacchi();
    void casellaSelezionata(Posizione);

};

#endif // MAINWINDOW_H
