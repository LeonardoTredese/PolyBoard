#ifndef GIOCO_H
#define GIOCO_H
#include "scacchiera.h"
#include <iostream>
#include <string>
#include "../pedina/id.hpp"
using std::cout; using std::endl;

class Gioco
{
protected:
    Scacchiera tavolo;
public:
    Gioco(int width, int heigth);
    virtual ~Gioco(){}
    void stampaTavolo() const;
    virtual char tipoGioco() const = 0;
    virtual void turno() = 0;
};

#endif