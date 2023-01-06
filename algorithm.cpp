#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main(int argc, char **argv)
{
    vector<int>vec1{1, 2, 3};
    vector<int>vec2{4, 5, 6};
    vector<int>res(6);
    merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), res.begin());
    for(auto elem : res)
        cout << elem <<  endl;

    vector<int>even, odd;
    even.resize(res.size()/2);
    odd.resize(res.size()/2);
    partition_copy(res.begin(), res.end(), odd.begin(), even.begin(),
    [](int number)
    {
        return (number%2) == 1;
    });
    cout << "Copied even numbers: " << endl;
    for(auto elem : even)
        cout << elem << endl;
    cout << "Copied odd number: " << endl;
    for(auto elem : odd)
        cout << elem << endl;
    return 0;
}