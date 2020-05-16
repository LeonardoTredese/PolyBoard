#ifndef ID_H
#define ID_H

#include "../colore.h"

class ID
{
private:
    const char tipo_pedina;
    const Colore colore;
public:
    ID(char _pedina, Colore _colore);
    char getTipo() const;
    Colore getColore() const;
    bool operator==(const ID&) const;
    bool operator!=(const ID&) const;
};

#endif // ID_H
