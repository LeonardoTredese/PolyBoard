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
    while(!scaccoMatto)
    {
        gioco.stampaTavolo();
        bool checkTurno;
        do
        {   
            int xI, yI, xF, yF;
            cout<<"Inserisci posizione iniziale:"<<endl;
            cin >> xI >> yI;
            cout<<"Inserisci posizione finale:"<<endl;
            cin>>xF>>yF;
            checkTurno = gioco.mossa(Posizione(xI, yI), Posizione(xF, yF));
        } while (!checkTurno);
        scaccoMatto = gioco.controlloVincitore();
    }
    return 0;
}
