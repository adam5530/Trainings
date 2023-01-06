#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
    string msg;
    int id;
};

int main(int argc, char**argv)
{
    vector<Data>vec{{"Monitor", 15}, {"Keyboard", 3}, {"SSD Drive", 7}, {"RAM memory", 13}};
    for(auto &elem : vec)
        cout << elem.msg << " " << elem.id << endl;
    cout << endl;
    auto isInRange = all_of(vec.begin(), vec.end(),
    [](Data d)
    {
        return (d.id > 0 && d.id < 20);
    });
    cout << "Check if is in range " << isInRange << endl;
    cout << "Sort values" << endl;
    sort(vec.begin(), vec.end(),
    [](Data &l, Data &r)
    {
        return l.id < r.id;
    });
    for(auto &elem : vec)
        cout << elem.msg << " " << elem.id << endl;
    cout << endl;
    return 0;
}