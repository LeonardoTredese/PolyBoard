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
    PedinaScacchi(Colore _colore, short int _x, short int _y);
};

#endif