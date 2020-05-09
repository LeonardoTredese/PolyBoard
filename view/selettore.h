#ifndef SELETTORE_H
#define SELETTORE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "../gioco/gioco.h"
#include "../gioco/scacchi.h"

class Selettore : public QWidget
{
    Q_OBJECT
    QVBoxLayout *mainLayout;
public:
    explicit Selettore(QWidget *parent = nullptr);

signals:
    void creaNuovoGioco(Gioco*);
private slots:
    void creaScacchi();
};

#endif // SELETTORE_H
