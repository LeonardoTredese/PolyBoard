#include "selettore_promozione_scacchi.h"

SelettorePromozioneScacchi::SelettorePromozioneScacchi(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QHBoxLayout(this);
    setLayout(mainLayout);
    
    QPushButton *regina = new QPushButton(this);
    regina->setText(QString("Regina"));
    
    QPushButton *cavallo = new QPushButton(this);
    cavallo->setText(QString("Cavallo"));
    
    QPushButton *torre = new QPushButton(this);
    torre->setText(QString("Torre"));
    
    QPushButton *alfiere = new QPushButton(this);
    alfiere->setText(QString("Alfiere"));

    connect(regina, SIGNAL(clicked()), this, SIGNAL(pedinaSelezionata('Q')));
    connect(cavallo, SIGNAL(clicked()), this, SIGNAL(pedinaSelezionata('N')));
    connect(torre, SIGNAL(clicked()), this, SIGNAL(pedinaSelezionata('R')));
    connect(alfiere, SIGNAL(clicked()), this, SIGNAL(pedinaSelezionata('B')));    
    
    gruppoSelezione->addButton(regina);
    gruppoSelezione->addButton(cavallo);
    gruppoSelezione->addButton(torre);
    gruppoSelezione->addButton(alfiere);
    
    connect(gruppoSelezione, SIGNAL(buttonClicked(int)), this, SLOT(close()));

    mainLayout->addWidget(regina);
    mainLayout->addWidget(cavallo);
    mainLayout->addWidget(torre);
    mainLayout->addWidget(alfiere);

    show();
}
