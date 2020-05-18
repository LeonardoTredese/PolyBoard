#include "colore.h"

std::string coloreToString(Colore c)
{
    switch(c)
    {
        case nero:
            return "nero";
        case bianco:
            return "bianco";
        case rosso:
            return "rosso";
        case verde:
            return "verde";
        case giallo:
            return "giallo";
        case blu:
            return "blu";
        case azzurro:
            return "azzurro";
        case viola:
            return "viola";
        case rosa:
            return "rosa";
        default:
            return "undefined_color";
    }
}