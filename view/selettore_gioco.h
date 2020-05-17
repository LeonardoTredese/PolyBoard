#ifndef SELETTORE_H
#define SELETTORE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QButtonGroup>

class SelettoreGioco : public QWidget
{
    Q_OBJECT
    QVBoxLayout *mainLayout;
    QButtonGroup *gruppoGiochi;
public:
    explicit SelettoreGioco(QWidget *parent = nullptr);
signals:
    void creaScacchi() const;
};

#endif // SELETTORE_H
