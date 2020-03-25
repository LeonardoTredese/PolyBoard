#ifndef PEDINASCACCHI_H
#define PEDINASCACCHI_H
#include "../pedina.h"
#include "../colore.h"

// BIANCO SOTTO E NERO SOPRA
// classe astratta, muovi non definito
class PedinaScacchi: public Pedina{
private:
    const ColoreBN colore;
public:
    ColoreBN getColore() const;
    PedinaScacchi(ColoreBN _colore);
    virtual PedinaScacchi* clone() const = 0;
};


#endif