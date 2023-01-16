#include <iostream>
#include <memory>

using namespace std;

class Abstract
{
public:
    virtual ~Abstract() {}
    virtual int getX() const = 0;
    virtual int getY() const 
    {
        cout << "Method getY() called in abstract class" << endl;
        return 100; 
    }
    int getZ() const
    {
        cout << "Method getZ() called in abstract class" << endl;
        return 200;
    }
};

class Interface
{
public:
    virtual ~Interface() {}
    virtual int getX() const = 0;
    virtual int getY() const = 0;
};

class AbstractDerived : public Abstract
{
private:
    int x;
    int y;
    int z;
public:
    AbstractDerived(int _x, int _y, int _z) : x(_x), y(_y), z(_z) { cout << "Called AbstractDerived CTOR" << endl; }
    int getX() const override
    {
        cout << "Called getX() from AbstractDerived" << endl;
        return x;
    }
    int getY() const override
    {
        cout << "Called getY() from AbstractDerived" << endl;
        return y;
    }
    int getZ() const //override -> cannot override
    {
        cout << "Called getZ() from AbstractDerived" << endl;
        return z;
    }
    ~AbstractDerived() { cout << "DTOR from AbstractDerived" << endl; }
};

class InterfaceDerived : public Interface
{
private:
    int x;
    int y;
public:
    InterfaceDerived(int _x, int _y) : x(_x), y(_y) { cout << "CTOR interface derived" << endl; }
    int getX() const override final
    {
        cout << "Called getX() from interface derived" << endl;
        return x;
    }
    int getY() const override final
    {
        cout << "Called getY() from interface derived" << endl;
        return y;
    }
    ~InterfaceDerived() { cout << "DTOR in interfance derived" << endl; }
};

int main(int argc, char **argv)
{
    cout << "Abstract class" << endl;
    unique_ptr<Abstract>abPtr = make_unique<AbstractDerived>(1, 2, 3);
    const int x = abPtr->getX();
    const int y = abPtr->getY();
    const int z = abPtr->getZ();
    cout << "x : " << x << ", y : " << y << ", z : " << z << endl;
    cout << "Derived abstract class" << endl;
    unique_ptr<AbstractDerived>abPtrDer = make_unique<AbstractDerived>(1, 2, 3);
    const int x1 = abPtrDer->getX();
    const int y1 = abPtrDer->getY();
    const int z1 = abPtrDer->getZ();
    cout << "x1 : " << x1 << ", y1 : " << y1 << ", z1 : " << z1 << endl;

    cout << "Interface" << endl; 
    unique_ptr<Interface>inter = make_unique<InterfaceDerived>(10, 20);
    const int intX = inter->getX();
    const int intY = inter->getY();
    cout << "x : " << intX << ", y : " << intY << endl;
    return 0;
}