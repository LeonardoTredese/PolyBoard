#ifndef SELETTORE_H
#define SELETTORE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QButtonGroup>

class Selettore : public QWidget
{
    Q_OBJECT
    QVBoxLayout *mainLayout;
    QButtonGroup *gruppoGiochi;
public:
    explicit Selettore(QWidget *parent = nullptr);
signals:
    void creaScacchi() const;
};

#endif // SELETTORE_H
