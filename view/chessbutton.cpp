#include "chessbutton.h"

ChessButton::ChessButton(const Posizione& pos_, QWidget* parent) : QPushButton(parent),pos(pos_)
{
    connect(this, SIGNAL(clicked()), this, SLOT(pulsantePremuto()));
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}

void ChessButton::pulsantePremuto()
{
    emit clicked(pos);
}
