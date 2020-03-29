#include "gioco.h"

Gioco::Gioco(int _width, int _height) : tavolo(_width, _height){}

void Gioco::stampaTavolo() const
{
    Scacchiera<SmartP>::const_iterator cit=tavolo.begin();
    cout << tipoGioco() << endl;
    for(int y=0; y<tavolo.getHeight(); ++y)
    {
        for(int x=0; x < tavolo.getWidth(); ++x)
        {
            ID id((**cit)->getId());
            cout<<id.getTipo()<<id.getColore()<<' ';
            ++cit;
        }
        cout<<endl;
    }
}