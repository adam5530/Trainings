#include <iostream>

using namespace std;

class MainBase
{
public:
    MainBase() { cout << "Main base CTOR" << endl; }
    ~MainBase() { cout << "Main base DTOR" << endl; }
};

class BaseFirst : virtual public MainBase
{
public:
    BaseFirst() { cout << "First base CTOR" << endl; }
    ~BaseFirst() { cout << "First base DTOR" << endl; }
};

class BaseSecond : virtual public MainBase
{
public:
    BaseSecond() { cout << "Second base CTOR" << endl; }
    ~BaseSecond() { cout << "Second base DTOR" << endl; }
};

class Derived : public BaseFirst, public BaseSecond
{
public:
    Derived() { cout << "Derived CTOR" << endl; }
    ~Derived() { cout << "Derived DTOR" << endl; }
};

int main(int argc, char **argv)
{
    Derived d;
    return 0;
}