#ifndef ID_H
#define ID_H

struct ID
{
    const char tipo_pedina;
    const int colore;
    ID(char _pedina, int _colore) : tipo_pedina(_pedina), colore(_colore){}
};

#endif