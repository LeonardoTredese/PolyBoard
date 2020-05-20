#include "selettore_promozione_scacchi.h"

SelettorePromozioneScacchi::SelettorePromozioneScacchi(QWidget *parent) : QWidget(parent), mainLayout(new QVBoxLayout()), gruppoSelezione(new QButtonGroup())
{
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint); // serve per impedire la chiusura della finestra
    setLayout(mainLayout);

    QLabel* info = new QLabel("Seleziona promozione pedone", this);
    info->setAlignment(Qt::AlignCenter);

    QPushButton *regina = new QPushButton(this);
    regina->setText(QString("Regina"));
    
    QPushButton *cavallo = new QPushButton(this);
    cavallo->setText(QString("Cavallo"));
    
    QPushButton *torre = new QPushButton(this);
    torre->setText(QString("Torre"));
    
    QPushButton *alfiere = new QPushButton(this);
    alfiere->setText(QString("Alfiere"));

    connect(regina, SIGNAL(clicked()), this, SLOT(reginaSel()));
    connect(cavallo, SIGNAL(clicked()), this, SLOT(cavalloSel()));
    connect(torre, SIGNAL(clicked()), this, SLOT(torreSel()));
    connect(alfiere, SIGNAL(clicked()), this, SLOT(alfiereSel()));
    
    gruppoSelezione->addButton(regina);
    gruppoSelezione->addButton(cavallo);
    gruppoSelezione->addButton(torre);
    gruppoSelezione->addButton(alfiere);
    
    connect(gruppoSelezione, SIGNAL(buttonClicked(int)), this, SLOT(close()));

    mainLayout->addWidget(info);
    mainLayout->addWidget(regina);
    mainLayout->addWidget(cavallo);
    mainLayout->addWidget(torre);
    mainLayout->addWidget(alfiere);

    show();
}

void SelettorePromozioneScacchi::reginaSel() const { emit pedinaSelezionata('Q'); }
void SelettorePromozioneScacchi::cavalloSel() const { emit pedinaSelezionata('N'); }
void SelettorePromozioneScacchi::torreSel() const { emit pedinaSelezionata('R'); }
void SelettorePromozioneScacchi::alfiereSel() const { emit pedinaSelezionata('B'); } 