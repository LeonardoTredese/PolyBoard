#ifndef GIOCO_H
#define GIOCO_H
#include "scacchiera.hpp"
#include "smartp.h"
#include <iostream>
#include <string>
using std::cout; using std::endl;

class Gioco
{
protected:
    Scacchiera<SmartP> tavolo;
public:
    Gioco(int _width, int _heigth);
    virtual ~Gioco(){}
    void stampaTavolo() const;
    virtual char tipoGioco() const = 0;
    virtual void turno() = 0;
};
#endif