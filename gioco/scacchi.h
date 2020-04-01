#ifndef SCACCHI_H
#define SCACCHI_H
#include "gioco.h"
#include <iostream>
#include "../colore.h"
#include "../pedina/scacchi/pedinascacchi.h"

class Scacchi : public Gioco {
public:
    Scacchi(int width=8, int height=8);
    virtual char tipoGioco() const;
    virtual bool turno(const Posizione& posIniziale, const Posizione& posFinale);
    bool scaccoAlRe(Colore re) const;
};

#endif