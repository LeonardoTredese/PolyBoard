#ifndef PEDINASCACCHI_H
#define PEDINASCACCHI_H
#include "../pedina.h"

enum Colore{bianco, nero};
// BIANCO A SINISTRA E NERO A DESTRA
// classe astratta, muovi non definito
class PedinaScacchi: public Pedina{
private:
    const Colore colore;
public:
    bool getColore() const;
    PedinaScacchi(bool _colore, short int _x, short int _y);
};

#endif