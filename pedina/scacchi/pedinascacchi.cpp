#include "pedinascacchi.h"
//COSTRUTTORE
PedinaScacchi::PedinaScacchi(Colore _colore, short int _x, short int _y): Pedina(_x, _y), colore(_colore){}

//METODO PER RITORNARE IL COLORE BIANCO(1), NERO(0)
Colore PedinaScacchi::getColore() const {return colore;}

