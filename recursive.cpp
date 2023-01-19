#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

void printer(int i)
{
    i += 2;
    cout << "Hello world " << i << endl;
}

void recursive(int i)
{
    cout << i << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    if(i < 0 || i > 20)
    {
        return;
    }
    else
    {
        recursive(i-2);
        printer(i);
    }
}

int main(int argc, char **argv)
{
    int x = 19;
    recursive(x);
    return 0;
}