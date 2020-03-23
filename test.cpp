class B {
    public:
    virtual B* foo() const =0;
};

class C: virtual public B{
public:
    virtual C* foo() const{
        return nullptr;
    }
};
class D: virtual public B{
public:
    virtual D* foo() const{
        return nullptr;
    }
};
class E: public C, public D{
public:
    virtual E* foo() const{
        return nullptr;
    }
};

int main()
{
    return 0;
}
