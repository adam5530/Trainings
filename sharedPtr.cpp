#include <iostream>
#include <memory>

using namespace std;

class Vehicle
{
public:
    Vehicle() = default;
    virtual const int getAge() const = 0;
    virtual const string getCompany() const = 0;
    virtual const int getPower() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle
{
private:
    int age;
    string companyName;
    int power;
public:
    Car(string _company, int _age, int _power) : companyName(_company), age(_age), power(_power) {}
    const int getAge() const override { return age; }
    const string getCompany() const override { return companyName; }
    const int getPower() const override { return power; }
    ~Car() {}
};

int main(int argc, char **argv)
{
    shared_ptr<Vehicle> merc = make_shared<Car>("Mercedes", 20, 300);
    cout << merc->getCompany() << " " << merc->getAge() << " " << merc->getPower() << endl;

    unique_ptr<Vehicle> opel = make_unique<Car>("Opel" , 25, 115);
    cout << opel->getCompany() << " " << opel->getAge() << " " << opel->getPower() << endl;

    return 0;
}