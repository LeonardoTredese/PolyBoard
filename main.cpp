#include <iostream>
#include "gioco/scacchi.h"
using namespace std;

int main()
{
    Scacchi gioco;

    /*
        NESSUN METODO PLAY IN GIOCO, SARÀ IL MAIN (GUI/CLI) A GESTIRE IL CICLO CON I TURNI RISPETTIVI;
        AD OGNI BUON FINE DI TURNO VERRÀ RICHIAMATO IL METODO DI SCACCO MATTO, CHE NEL CASO DECRETERÀ 
        IL VINCITORE
    */
    bool scaccoMatto(false);
    Colore vincitore;
    gioco.stampaTavolo();
    while(!scaccoMatto)
    {
        bool checkTurno;
        do
        {   
            cout<<"Giocatore corrente: " <<gioco.getGiocatoreCorrente()<<endl;
            int xI, yI, xF, yF;
            cout<<"Inserisci posizione iniziale:"<<endl;
            cin >> xI >> yI;
            cout<<"Inserisci posizione finale:"<<endl;
            cin>>xF>>yF;
            checkTurno = gioco.mossa(Posizione(xI, yI), Posizione(xF, yF));
            if(checkTurno)
                cout << "Pedina mossa" << endl;
            else
                cout << "Mossa non valida" << endl;
        } while (!checkTurno);
        gioco.stampaTavolo();
        scaccoMatto = gioco.controlloVincitore();
        if(scaccoMatto)
            vincitore = gioco.getGiocatoreCorrente();
        gioco.cambioTurno();
    }
    cout << "Scacco matto! Vince il giocatore " << vincitore << endl;
    return 0;
}
