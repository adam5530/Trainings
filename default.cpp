#include <iostream>

using std::cout;
using std::endl;

class Int
{
private:
    int x;
public:
    Int() = default;
    Int(int _x) : x(_x) { cout << "X set by CTOR " << x << endl; }
    Int(Int&) = default;
    Int(Int&&) = default;
    Int& operator=(Int&) = default;
    Int& operator=(Int&&) = default;
    ~Int() = default;
    int getX() { return x; }
    void setX(int _x) { x = _x; }
};

class Point
{
private:
    int x{0};
    int y{0};
public:
    Point() = default;
    Point(double value) = delete;
    Point(int value)
    {
        x = value;
        y = value;
    }
    int getX() { return x; }
    int getY() { return y; }
    void setX(int nx) { x = nx; }
    void setY(int ny) { y = ny; }
    void setY(double) = delete;
    void setXY(int, int) = delete;
    Point operator+(Point&pt)
    {
        Point p;
        p.x = pt.x;
        p.y = pt.y;
        return p;
    }
    Point operator-(void)
    {
        Point p;
        p.x = -x;
        p.y = -y;
        return p;
    }
    void show(const char*objName)
    {
        cout << objName << endl;
        cout << "x " << x << " y " << y << endl;
        cout << endl;
    }
};

class Ptr
{
private:
    int *ptr;
public:
    Ptr() { ptr = nullptr; }
    Ptr(int val) : ptr(new int(val)) {}
    /*Ptr&(Ptr *other)
    {
        ptr = other.ptr;
    }*/
    int getVal() { return *ptr; }
    int *getPtr() { return ptr; }
    Ptr(Ptr&) = default;
    Ptr& operator =(Ptr&) = default;
    ~Ptr() = default;
};

int main(int argc, char **argv)
{
    Int i1(7);
    Int i2 = i1;
    cout << i2.getX() << endl;

    Int i3;
    i3.setX(18);
    i3 = i2;
    cout << i3.getX() << endl;

    Point p1(5);
    p1.show("p1");
    p1.setX(3.9);
    //p1.setY(8.4);// -> error -> deleted
    p1.show("p1");

    Point p2;
    p2.show("p2");

    {
        Ptr p1(10);
        cout << p1.getVal() << " " << p1.getPtr() << endl;
        Ptr p2;
        p2 = p1;
        cout << p2.getVal() << " " << p2.getPtr() << endl;
    }
    return 0;
}