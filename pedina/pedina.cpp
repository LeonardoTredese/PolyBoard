#include "pedina.h"

ID::ID(char _pedina, Colore _colore) : tipo_pedina(_pedina), colore(_colore) {}

char ID::getTipo() const { return tipo_pedina; }
Colore ID::getColore() const { return colore; }
bool ID::operator==(const ID& id) const
{
    return id.colore==colore && id.tipo_pedina==tipo_pedina;
}
bool ID::operator!=(const ID& id) const
{
    return id.colore!=colore || id.tipo_pedina!=tipo_pedina;
}

Pedina::Pedina(Colore _colore): colore(_colore){}

Colore Pedina::getColore() const {return colore;}

Pedina::~Pedina(){}

void Pedina::pedinaMossa(){}
