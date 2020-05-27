#ifndef PEDINASCACCHI_H
#define PEDINASCACCHI_H
#include "../pedina.h"

// BIANCO SOTTO E NERO SOPRA
// classe astratta, muovi non definito
class PedinaScacchi: public Pedina{
public:
    PedinaScacchi(Colore colore_, bool primaMossa_ = true);
    virtual PedinaScacchi* clone() const = 0;
};

#endif