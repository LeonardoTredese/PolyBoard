#include "gioco.h"

Gioco::Gioco(int width, int height) try : tavolo(width, height){}
catch(ErroreScacchiera(BOARD_TOO_SMALL)){
    // TODO
}

void Gioco::stampaTavolo() const{
    Scacchiera::const_iterator cit=tavolo.begin();
    cout << tipoGioco() << endl;
    for(int y=0; y<tavolo.getHeight(); ++y)
    {
        for(int x=0; x<tavolo.getWidth(); ++x)
        {
            ID id((*cit)->getId());
            cout<<id.tipo_pedina<<id.colore<<' ';
            ++cit;
        }
        cout<<endl;
    }
}