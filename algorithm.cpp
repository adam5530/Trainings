#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Data
{
    string msg;
    int id;
};

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

    vector<int>data{1, 6, 3, 0};
    do
    {
        next_permutation(data.begin(), data.end());
        for(auto &elem : data)
            cout << elem << " ";
        cout << endl;
    }while(!is_sorted(data.begin(), data.end()));

    auto isInRange = all_of(data.begin(), data.end(),
    [](int i)
    {
        return (i >= 0 && i < 10);
    });
    cout << isInRange << endl;
    return 0;
}