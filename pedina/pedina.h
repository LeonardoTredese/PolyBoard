#ifndef PEDINA_H
#define PEDINA_H

class Pedina{
public:
    virtual ~Pedina();
    // PRE: xI e yI sono le posizioni attuali della pedina ll'interno della scacchiera, e 
    // xF e yF sono posizioni dopo il movimento valide all'interno della scacchiera
    virtual bool controlloMossa(short int xI, short int yI,short int xF, short int yF) const =0;  
    //POST: ritorna un true se è possibile spostare la pedina su (xF,yF), altrimenti viene ritornato false.
    
    //METODO CHE STAMPA LA PEDINA(IN VERSIONE CLI)
    //virtual char* stampaPedina()=0;
};

#endif