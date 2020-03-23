#ifndef PEDINA_H
#define PEDINA_H
#include <string>

class Pedina{
public:
    virtual ~Pedina();
    // PRE: xI e yI sono le posizioni attuali della pedina ll'interno della scacchiera, e 
    // xF e yF sono posizioni dopo il movimento valide all'interno della scacchiera
    virtual bool controlloMossa(short int xI, short int yI,short int xF, short int yF) const =0;  
    //POST: ritorna un true se è possibile spostare la pedina su (xF,yF), altrimenti viene ritornato false.
    virtual Pedina* clone() const = 0;
    
    virtual std::string getId() const = 0;
    // ritorna l'id della pedina che verrà interpretato in una certa maniera in base all'interfaccia
    
};

#endif