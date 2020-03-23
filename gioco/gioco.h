#ifndef GIOCO_H
#define GIOCO_H
#include "scacchiera.h"

class Gioco
{
protected:
    Scacchiera tavolo;
public:
    Gioco(int width, int heigth);
    virtual ~Gioco(){}
    void stampaTavolo() const;
    virtual void turno() = 0;
};

#endif