#ifndef SCACCHI_H
#define SCACCHI_H
#include "gioco.h"
#include <iostream>
#include "../colore.h"
#include "../pedina/scacchi/pedone.h"
#include "../pedina/scacchi/torre.h"
#include "../pedina/scacchi/alfiere.h"
#include "../pedina/scacchi/cavallo.h"
#include "../pedina/scacchi/regina.h"
#include "../pedina/scacchi/re.h"
using std::cout; using std::endl;

class Scacchi : public Gioco {
public:
    Scacchi();
    virtual char tipoGioco() const;
    virtual bool mossa(const Posizione& posIniziale, const Posizione& posFinale);
    bool scaccoAlRe(Colore re) const;
    virtual void cambioTurno();
    virtual bool controlloVincitore() const;
    bool scaccoMatto(Colore re) const;
};

#endif