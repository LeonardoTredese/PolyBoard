#include "tipogioco.h"

std::string tipoGiocoToString(const TipoGioco& t)
{
    switch(t)
    {
        case chess:
            return "chess";
        // altri giochi
        default:
            return "";
    }
}