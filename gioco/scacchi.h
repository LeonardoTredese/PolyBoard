#ifndef SCACCHI_H
#define SCACCHI_H
#include "gioco.h"
#include <iostream>
#include "../pedina/pedina.h"

class Scacchi : public Gioco{
public:
    Scacchi(int width, int height);
    virtual char tipoGioco() const;
    virtual void turno();
    bool scaccoAlRe(ColoreBN re) const;
};

#endif