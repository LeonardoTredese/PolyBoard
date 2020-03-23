#include "gioco.h"

Gioco::Gioco(int width, int height) try : tavolo(width, height){}
catch(ErroreScacchiera(BOARD_TOO_SMALL)){
    // TODO
}