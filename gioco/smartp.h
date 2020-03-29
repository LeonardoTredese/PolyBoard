#ifndef SMARTP_H
#define SMARTP_H
#include "../pedina/pedina.h"
class SmartP
{
private:
    Pedina* p;
public:
    SmartP(const Pedina* sp=nullptr);
    SmartP(const SmartP&);
    ~SmartP();
    SmartP& operator=(const SmartP&);
    Pedina& operator*() const;
    Pedina* operator->() const;
};
#endif