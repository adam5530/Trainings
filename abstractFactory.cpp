#include <iostream>
#include <memory>
#include <utility>

using namespace std;

class Chair
{
public:
    Chair() = default;
    virtual int getLegs() const = 0;
    virtual bool getSitBack() const = 0;
};

class OldChair : public Chair
{
private:
    const int legs;
    const bool sitBack;
public:
    OldChair(const int _l, const bool _s) : legs(_l), sitBack(_s) { cout << "Created old chair" << endl; }
    int getLegs() const override { return legs; }
    bool getSitBack() const override { return sitBack; }
};

class ModernChair : public Chair
{
private:
    const int legs;
    const bool sitBack;
public:
    ModernChair(const int _l, const bool _s) : legs(_l), sitBack(_s) { cout << "Created modern chair" << endl; }
    int getLegs() const override { return legs; }
    bool getSitBack() const override { return sitBack; }
};

class AbstractFactory
{
public:
    AbstractFactory() = default;
    virtual Chair *createChair() const = 0;
};

class OldFactory : public AbstractFactory
{
    pair<int, bool>params;
public:
    OldFactory(pair<int, bool> _p) : params(_p) {}
    Chair *createChair() const  override { return new OldChair(params.first, params.second); }
};

class ModerFactory : public AbstractFactory
{
    pair<int, bool>params;
public:
    ModerFactory(pair<int, bool>_p) : params(_p) {}
    Chair *createChair() const override { return new ModernChair(params.first, params.second); }
};

void client(const AbstractFactory &factory)
{
    const Chair *chair = factory.createChair();
    cout << "Number of legs : " << chair->getLegs() << ", has sitBack : " << chair->getSitBack() << endl;
    delete chair;
}

int main(int argc, char **argv)
{
    auto oldParams = make_pair<int, bool>(4, true);
    shared_ptr<OldFactory>old = make_shared<OldFactory>(oldParams);
    client(*old);

    auto modernParams = make_pair<int, bool>(6, false);
    shared_ptr<ModerFactory>modern = make_shared<ModerFactory>(modernParams);
    client(*modern);
    return 0;
}