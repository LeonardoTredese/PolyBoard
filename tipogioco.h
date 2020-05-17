#ifndef TIPOGIOCO_H
#define TIPOGIOCO_H
#include <string>

enum TipoGioco
{
    chess = 0
    // altri giochi
};

std::string tipoGiocoToString(const TipoGioco&);

#endif