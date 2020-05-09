#include "selettore.h"

Selettore::Selettore(QWidget *parent) : QWidget(parent), mainLayout(new QVBoxLayout(this))
{
    setLayout(mainLayout);
    QPushButton *pulsanteScacchi=new QPushButton(this);
    pulsanteScacchi->setText("Scacchi");
    mainLayout->addWidget(pulsanteScacchi);
    connect(pulsanteScacchi, SIGNAL(clicked()), this, SLOT(creaScacchi()));
    show();
}

void Selettore::creaScacchi()
{
    Gioco *nuovoGioco = new Scacchi();
    emit creaNuovoGioco(nuovoGioco);
    close();
}

