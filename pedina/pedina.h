#ifndef PEDINA_H
#define PEDINA_H
#include <string>

enum ColoreBN{nero,bianco};

class ID
{
private:
    const char tipo_pedina;
    const int colore;
public:
    ID(char _pedina, int _colore);
    char getTipo() const;
    int getColore() const;
    bool operator==(const ID&) const;
    bool operator!=(const ID&) const;
};

class Pedina{
public:
    virtual ~Pedina();
    // PRE: xI e yI sono le posizioni attuali della pedina ll'interno della scacchiera, e 
    // xF e yF sono posizioni dopo il movimento valide all'interno della scacchiera
    virtual bool controlloMossa(short int xI,short int yI,short int xF,short int yF, bool eat=false) const = 0;  
    //POST: ritorna un true se è possibile spostare la pedina su (xF,yF), altrimenti viene ritornato false.
    virtual Pedina* clone() const = 0;
    
    virtual ID getId() const = 0;
    // ritorna l'id della pedina che verrà interpretato in una certa maniera in base all'interfaccia
    
};

#endif