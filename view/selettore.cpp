#include "selettore.h"

Selettore::Selettore(QWidget *parent) : QWidget(parent), mainLayout(new QVBoxLayout(this))
{
    setLayout(mainLayout);
    QPushButton *pulsanteScacchi=new QPushButton(this);
    pulsanteScacchi->setText("Scacchi");
    mainLayout->addWidget(pulsanteScacchi);
    //il pulsante scacchi, se premuto
    //verrà raccolto da "creaScacchi"
    connect(pulsanteScacchi, SIGNAL(clicked()), this, SLOT(creaScacchi()));
    show();
}


//CreaScacchi, crea il nuovo tipo di gioco, in
//base al pulsante premuto, in questo caso solamente "Scacchi"
//ed emetterà il segnale "creaNuovoGioco", il quale passa
//il nuovo gioco alla mainWindow.
void Selettore::creaScacchi()
{
    Gioco *nuovoGioco = new Scacchi();
    emit creaNuovoGioco(nuovoGioco);
    close();
}

