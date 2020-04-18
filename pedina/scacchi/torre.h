#ifndef TORRE_H
#define TORRE_H
#include "movimentoCroce.h"

class Torre: virtual public MovimentoCroce
{
private:
    bool primaMossa;//indica se la prima mossa è stata effettuata 1 se deve essere ancora spostata, 0 altrimenti    
public:
    Torre(Colore _colore, bool _primaMossa=true);
    virtual Torre* clone() const;
    virtual ID getId() const;
    virtual void pedinaMossa();
    bool getPrimaMossa() const;
};

#endif