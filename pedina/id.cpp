#include "id.h"

ID::ID(char pedina_, Colore colore_, bool primaMossa_) : tipo_pedina(pedina_), colore(colore_), primaMossa(primaMossa_) {}

char ID::getTipo() const { return tipo_pedina; }
Colore ID::getColore() const { return colore; }
bool ID::getPrimaMossa()const{ return primaMossa; }
bool ID::operator==(const ID& id) const
{
    return id.colore==colore && id.tipo_pedina==tipo_pedina;
}
bool ID::operator!=(const ID& id) const
{
    return id.colore!=colore || id.tipo_pedina!=tipo_pedina;
}
