#ifndef PEDINA_H
#define PEDINA_H
#include <string>
#include "../gioco/posizione.h"
#include "../colore.h"
#include <list>

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

class Pedina{
    const Colore colore;
public:
    Pedina(Colore _colore);
    virtual ~Pedina();
    // PRE: inizio e fine sono due posizioni all'interno della scacchiera
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const = 0;  
    //POST: ritorna una lista delle posizioni da attraversare per arrivare a fine da inizio (inclusa quella finale)
    //      se non ci posso andare ritorno la lista vuota
    virtual Pedina* clone() const = 0;
    Colore getColore() const;
    virtual ID getId() const = 0;
    // ritorna l'id della pedina che verrà interpretato in una certa maniera in base all'interfaccia
};

#endif