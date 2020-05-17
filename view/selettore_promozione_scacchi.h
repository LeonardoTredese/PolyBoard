#ifndef SELETTORE_PROMOZIONE_H
#define SELETTORE_PROMOZIONE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QButtonGroup>

class SelettorePromozioneScacchi : public QWidget
{
    Q_OBJECT
    QHBoxLayout *mainLayout;
    QButtonGroup *gruppoSelezione;
    
public:
    explicit SelettorePromozioneScacchi(QWidget *parent = nullptr);
signals:
    
    void pedinaSelezionata(char) const;
};

#endif // SELETTORE_H
