#include "pedina.h"

Pedina::Pedina(Colore colore_, bool primaMossa_): colore(colore_), primaMossa(primaMossa_){}

Colore Pedina::getColore() const {return colore;}

Pedina::~Pedina(){}

void Pedina::pedinaMossa(){ primaMossa = false; }

bool Pedina::getPrimaMossa() const { return primaMossa; }
