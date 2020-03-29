#ifndef PEDINASCACCHI_H
#define PEDINASCACCHI_H
#include "../pedina.h"

enum ColoreBN{nero,bianco};

// BIANCO SOTTO E NERO SOPRA
// classe astratta, muovi non definito
class PedinaScacchi: public Pedina{
private:
    const ColoreBN colore;
public:
    ColoreBN getColore() const;
    PedinaScacchi(ColoreBN _colore);
    virtual PedinaScacchi* clone() const = 0;
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const = 0;
};


#endif