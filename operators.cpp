#include <iostream>
#include <utility>

using namespace std;

class Calc
{
private:
    int x, y;
public:
    pair<int, int> getVals() { return make_pair<int, int>(move(x), move(y)); }
    Calc() : x{0}, y{0} {}
    Calc(int _x, int _y) : x{_x}, y{_y} {}
    Calc& operator=(const Calc& other)
    {
        if(this == &other)
            return *this;
        x = other.x;
        y = other.y;
        return *this;
    }
    Calc(const Calc& old)
    {
        x = old.x;
        y = old.y;
    }
    inline bool operator==(const Calc& right)
    {
        return (x == right.x && y == right.y);
    }
    Calc operator+(const Calc& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    Calc operator*(const Calc& other)
    {
        x *= other.x;
        y *= other.y;
        return *this;
    }
};

int main(int argc, char **argv)
{
    Calc cl1{3, 5};
    Calc cl2{3, 5};
    bool isEqual = cl1 == cl2;
    cout << isEqual << endl;

    Calc cl3 = cl2;
    isEqual = cl3 == cl1;
    cout << isEqual << endl;

    Calc cl4;
    cl4 = cl1 + cl2;
    cout << cl4.getVals().first << " " << cl4.getVals().second << endl;
    return 0;
}