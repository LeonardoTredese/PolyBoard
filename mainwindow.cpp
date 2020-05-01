#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent) : QMainWindow(parent)
{
    mainLayout = new QVBoxLayout(this);
    gridLayout = new QGridLayout();

    //aggiungo menù
    addMenu();
    addButtons();

    mainLayout->addLayout(gridLayout);
}



void mainWindow::addMenu(){
    // Creare la barra dei menu, poi il menu e infine le azioni
    QMenuBar* menubar = new QMenuBar(this);
    //MENU FILE
    QMenu* file = new QMenu("File",menubar);
    QAction* exit = new QAction("Exit",file);
    QAction* save = new QAction("Salva",file);
    QAction* save_name = new QAction("Salva con Nome",file);
    QAction* load = new QAction("Carica",file);
    QAction* nuova= new QAction("Nuova Partita",file);

    file->addAction(nuova);
    file->addAction(load);
    file->addAction(save);
    file->addAction(save_name);
    file->addAction(exit);

    //MENU PARTITA
    QMenu *partita = new QMenu("Partita",menubar);

    QAction* reset = new QAction("Reset",partita);
    QAction *resa = new QAction("Dichiara Resa",partita);
    QAction *pareggio = new QAction("Dichiara Pareggio",partita);

    partita->addAction(reset);
    partita->addAction(resa);
    partita->addAction(pareggio);

    //aggiungo i menu alla menubar
    menubar->addMenu(file);
    menubar->addMenu(partita);

    // Aggiungo la menubar al layout
    mainLayout->addWidget(menubar);
}

void mainWindow::addButtons(int width, int height){

    for (int i = 0; i < 64; i++){
        // Creo un bottone -> QPushButton
        QPushButton *button = new QPushButton(this);

        // Dare una policy per le dimensioni
        button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        // Aggiungere al layout
        gridLayout->addWidget(button,i/8,i%8);
    }
}
