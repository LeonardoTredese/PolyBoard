#ifndef PEDINASCACCHI_H
#define PEDINASCACCHI_H
#include "../pedina.h"

enum Colore{bianco, nero};

// BIANCO SOTTO E NERO SOPRA
// classe astratta, muovi non definito
class PedinaScacchi: public Pedina{
private:
    const Colore colore;
public:
    Colore getColore() const;
    PedinaScacchi(Colore _colore);
    virtual PedinaScacchi* clone() const = 0;
    virtual std::string getId() const = 0;
    // R N B Q K P
    /*
     * c = chess
     * R = rook = torre
     * N = knight = cavaliere
     * B = bishop = alfiere
     * Q = queen
     * K = king
     * P = pawn = pedone
     * 0 = nero
     * 1 = bianco
     * L'id è cosi composto:
     * - c (minuscola) indica pedina di scacchi (chess)
     * - la seconda lettera (maiuscola) indica il tipo di pedina
     * - l'ultimo numero 0/1 il colore nero/bianco
    */
};


#endif