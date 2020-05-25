#ifndef SELETTORE_H
#define SELETTORE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>

class SelettoreGioco : public QWidget
{
    Q_OBJECT
    QVBoxLayout *mainLayout;
    QButtonGroup *gruppoGiochi;
public:
    explicit SelettoreGioco(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent* event);
signals:
    void creaScacchi() const;
    void finestraChiusa();
};

#endif // SELETTORE_H
