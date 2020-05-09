#include "gioco.h"

Gioco::Gioco(int _width, int _height, Colore giocatore_iniziale) : width(_width), height(_height), tavolo(_width, _height), giocatore_corrente(giocatore_iniziale){}

void Gioco::stampaTavolo() const
{
    Scacchiera::const_iterator cit=tavolo.begin();
    cout << tipoGioco() << endl;
    cout << "  ";
    for(int x=0; x < tavolo.getWidth(); ++x)
        cout << x << "  ";
    cout << endl;
    for(int y=0; y<tavolo.getHeight(); ++y)
    {
        for(int x=0; x < tavolo.getWidth()+1; ++x)
        {
            if(x == 0)
                cout << y << " ";
            else 
            {
                if(*cit)
                {
                    ID id((*cit)->getId());
                    cout<<id.getTipo()<<id.getColore()<<' ';
                }
                else
                    cout<<"░░ ";
                ++cit;
            }
        }
        cout<<endl;
    }
}

Colore Gioco::getGiocatoreCorrente() const{
    return giocatore_corrente;
}

int Gioco::getWidth()const
{
    return width;
}

int Gioco::getHeight() const
{
    return height;
}