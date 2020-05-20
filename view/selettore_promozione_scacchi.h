#ifndef SELETTORE_PROMOZIONE_H
#define SELETTORE_PROMOZIONE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>

class SelettorePromozioneScacchi : public QWidget
{
    Q_OBJECT
    QVBoxLayout *mainLayout;
    QButtonGroup *gruppoSelezione;
public:
    explicit SelettorePromozioneScacchi(QWidget *parent = nullptr);
signals:
    void pedinaSelezionata(char) const;
private slots:
    void reginaSel() const;
    void cavalloSel() const;
    void alfiereSel() const;
    void torreSel() const;
};

#endif // SELETTORE_H
