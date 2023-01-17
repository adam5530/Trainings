#include <iostream>

using namespace std;

class Interface
{
public:
    Interface() = default;
    virtual void method() = 0;
    //virtual void xxx() = 0; -> error -> method in Derived not overriden
    virtual ~Interface() = default;
};

class Derived : public Interface
{
public:
    Derived() = default;
    void method() override final
    {
        cout << "method" << endl;
    }
    ~Derived() = default;
};

int main(int argc, char **argv)
{
    Interface *ptr = new Derived();
    ptr->method();
    delete ptr;
    return 0;
}