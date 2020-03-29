#include "pedina.h"

ID:ID(char _pedina, int _colore) : tipo_pedina(_pedina), colore(_colore) {}

char ID::getTipo() const { return tipo_pedina; }
int ID::getColore() const { return colore; }
bool ID::operator==(const ID& id) const
{
    return id.colore==colore && id.tipo_pedina==tipo_pedina;
}
bool ID::operator!=(const ID& id) const
{
    return id.colore!=colore || id.tipo_pedina!=tipo_pedina;
}

Pedina::~Pedina(){}
