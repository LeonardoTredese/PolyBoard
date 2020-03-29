#include "smartp.h"

SmartP::SmartP(const Pedina* _p) : p(_p ? _p->clone() : nullptr) {}
SmartP::SmartP(const SmartP& sp) : p(sp.p ? sp.p->clone() : nullptr) {}
SmartP::~SmartP() { delete p; }
SmartP& SmartP::operator=(const SmartP& sp)
{
    if(this != &sp)
    {
        delete p;
        p = sp.p ? sp.p->clone() : nullptr; 
    }
    return *this;
}
Pedina& SmartP::operator*() const { return *p;}
Pedina* SmartP::operator->() const { return p;}
