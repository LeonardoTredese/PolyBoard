#ifndef GIOCO_H
#define GIOCO_H
#include "scacchiera.h"
#include "../pedina/pedina.h"
#include "../tipogioco.h"

class Gioco
{
private:
    int width, height;
protected:
    Scacchiera tavolo;
    Colore giocatore_corrente;
public:
    Gioco(int _width, int _heigth, Colore giocatore_iniziale);
    virtual ~Gioco(){}
    virtual TipoGioco tipoGioco() const = 0;
    virtual bool mossa(const Posizione& posIniziale, const Posizione& posFinale) = 0;
    virtual void cambioTurno() = 0;
    virtual bool controlloVincitore() const = 0;
    Colore getGiocatoreCorrente() const;
    ID* getIdPedina(const Posizione&) const;
    int getWidth() const;
    int getHeight() const;
    virtual Gioco* clone() const = 0;
};
#endif
