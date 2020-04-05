#include "gioco.h"

Gioco::Gioco(int _width, int _height, Colore giocatore_iniziale) : tavolo(_width, _height), giocatore_corrente(giocatore_iniziale){}

void Gioco::stampaTavolo() const
{
    Scacchiera<SmartP>::const_iterator cit=tavolo.begin();
    cout << tipoGioco() << endl;
    for(int y=0; y<tavolo.getHeight(); ++y)
    {
        for(int x=0; x < tavolo.getWidth(); ++x)
        {
            if(*cit)
            {
                ID id((**cit)->getId());
                cout<<id.getTipo()<<id.getColore()<<' ';
            }
            else
                cout<<"XX ";
            ++cit;
        }
        cout<<endl;
    }
}
