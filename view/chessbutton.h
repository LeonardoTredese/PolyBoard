#ifndef CHESSBUTTON_H
#define CHESSBUTTON_H

#include <QWidget>
#include <QPushButton>
#include "../posizione.h"

class ChessButton : public QPushButton
{
    Q_OBJECT
public:
    ChessButton(const Posizione& pos_, QWidget* parent = nullptr);
private:
    const Posizione pos;
private slots:
    //Tale slot serve per inviare la Posizione del bottone al verificarsi dell'evento clicked()
    void pulsantePremuto();
signals:
    // Tale segnale emetterà effetivamente la Posizione relativa al bottone, la quale verrà passata al controller
    // per effettuare le opportune operazioni sulle pedine della scacchiera.
    void clicked(Posizione);
};

#endif // CHESSBUTTON_H
