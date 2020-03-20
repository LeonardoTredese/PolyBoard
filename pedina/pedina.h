#ifndef PEDINA_H
#define PEDINA_H

class Pedina{
private:
    short int x, y;  // posizione
protected:
    //METODI SETTER
    void setX(short int _x);
    void setY(short int _y);
public:
    Pedina(short int _x, short int _y);
    virtual ~Pedina();
    // PRE: _x e _y sono posizioni valide all'interno della scacchiera
    virtual bool controlloMossa(short int _x, short int _y) const =0;  
    //POST: ritorna un true se è possibile spostare la pedina, altrimenti viene ritornato false.
    short int getX() const;     //ritorna la posizione sull'asse x
    short int getY() const;     //ritorna la posizione sull'asse y
};

#endif