#include "pedinascacchi.h"
//COSTRUTTORE
PedinaScacchi::PedinaScacchi(bool _colore, short int _x, short int _y): Pedina(_x, _y), colore(_colore){}

//METODO PER RITORNARE IL COLORE BIANCO(1), NERO(0)
bool PedinaScacchi::getColore() const {return colore;}

