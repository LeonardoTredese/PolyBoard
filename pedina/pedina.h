#ifndef PEDINA_H
#define PEDINA_H
#include <string>
#include "../posizione.h"
#include "../colore.h"
#include "id.h"
#include <list>

class Pedina{
private:
    const Colore colore;
    bool primaMossa;
public:
    Pedina(Colore colore_, bool primaMossa_ = true);
    virtual ~Pedina();
    // PRE: inizio e fine sono due posizioni all'interno della scacchiera
    virtual std::list<Posizione> controlloMossa(const Posizione& inizio, const Posizione& fine, bool eat=false) const = 0;  
    //POST: ritorna una lista delle posizioni da attraversare per arrivare a fine da inizio (inclusa quella finale)
    //      se non ci posso andare ritorno la lista vuota
    virtual Pedina* clone() const = 0;
    Colore getColore() const;
    virtual ID getId() const = 0;
    // ritorna l'id della pedina che verrà interpretato in una certa maniera in base all'interfaccia
    virtual void pedinaMossa();
    virtual bool getPrimaMossa() const;
};

#endif