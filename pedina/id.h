#ifndef ID_H
#define ID_H

#include "../colore.h"

class ID
{
private:
    const char tipo_pedina;
    const Colore colore;
    const bool primaMossa;
public:
    ID(char pedina_, Colore colore_, bool primaMossa_ = false);
    char getTipo() const;
    bool getPrimaMossa() const;
    Colore getColore() const;
    bool operator==(const ID&) const;
    bool operator!=(const ID&) const;
};

#endif // ID_H
