#include "pedinascacchi.h"
//COSTRUTTORE
PedinaScacchi::PedinaScacchi(Colore _colore): colore(_colore){}

Colore PedinaScacchi::getColore() const {return colore;}

std::string PedinaScacchi::getId() const {
   return std::to_string(colore);
}