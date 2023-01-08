#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int *ptr = new int(10);
    cout << *ptr << endl;
    delete ptr;
    //*ptr = 20;
    //cout << *ptr << endl;
    return 0;
}