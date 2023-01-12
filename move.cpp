#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Car
{
private:
    int maxSpeed;
    int weight;
    char *company;
public:
    Car()
    : maxSpeed{0}
    , weight{0}
    , company{nullptr}
    {

    }
    Car(int _speed, int _weight, const char* p)
    : maxSpeed{_speed}
    , weight{_weight}
    {
        size_t size = std::strlen(p) + 1;
        company = new char[size];
        std::memcpy(company, p, size);
    }
    Car(const Car& other)
    {
        cout << "Copy CTOR" << endl;
        size_t size = std::strlen(other.company) + 1;
        company = new char[size];
        std::memcpy(company, other.company, size);
        maxSpeed = other.maxSpeed;
        weight = other.weight;
    }
    Car& operator=(const Car& other)
    {
        cout << "Copy operator assignement" << endl;
        size_t size = std::strlen(other.company) + 1;
        company = new char[size];
        std::memcpy(company, other.company, size);
        maxSpeed = other.maxSpeed;
        weight = other.weight;
        return *this;
    }
    Car(Car&& other)
    {
        cout << "Move CTOR" << endl;
        company = other.company;
        other.company = nullptr;
        maxSpeed = other.maxSpeed;
        other.maxSpeed = 0;
        weight = other.weight;
        other.weight = 0;
    }
    Car& operator=(Car&& other)
    {
        cout << "Move assignement operator" << endl;
        company = other.company;
        other.company = nullptr;
        maxSpeed = other.maxSpeed;
        other.maxSpeed = 0;
        weight = other.weight;
        other.weight = 0;
        return *this;
    }
    ~Car()
    {
        delete []company;
    }
    void printVals()
    {
        if(!company)
        {
            cout << "Nullptr" << endl;
            return;
        }
        cout << "Max speed = " << maxSpeed << " km/h, weight = " << weight << " kg :::: " << company << endl;
    }
};

int main(int argc, char **argv)
{
    Car mercedes(200, 1400, "Mercedes");
    mercedes.printVals();

    Car mercedes2;
    mercedes2 = mercedes;   //copy operator assignement
    mercedes2.printVals();

    Car mercedes3 = mercedes;   //copy CTOR
    mercedes3.printVals();

    Car mercedes4(move(mercedes));  //Move CTOR
    mercedes4.printVals();
    mercedes.printVals();

    Car opel(180, 1200, "Opel");
    Car opel1;
    opel1 = std::move(opel);  //move operator assignement
    opel1.printVals();
    opel.printVals();
    return 0;
}