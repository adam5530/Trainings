#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    vector<int>v1{1, 2, 3, 4, 5};
    vector<int>v2{6, 7, 8, 9, 10};
    for(auto &elem : v1)
        cout << elem << " ";
    cout << endl;
    for(auto &elem : v2)
        cout << elem << " ";
    cout << endl;
    swap(v1, v2);
    for(auto &elem : v1)
        cout << elem << " ";
    cout << endl;
    for(auto &elem : v2)
        cout << elem << " ";
    cout << endl;
    return 0;
}