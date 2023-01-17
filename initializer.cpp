#include <iostream>
#include <initializer_list>

using namespace std;

class Initializer
{
private:
    int *arr;
    unsigned int arrSize;
public:
    Initializer(const initializer_list<int>&l) : arr{nullptr}
    {
        if(l.size())
        {
            arrSize = l.size();
            arr = new int[l.size()];
            unsigned int counter{0};
            for(auto it = l.begin(); it != l.end(); ++it, counter++)
                arr[counter] = *it;
        }
    }
    void show()
    {
        for(unsigned int i = 0; i < arrSize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main(int argc, char **argv)
{
    Initializer in = {1, 2, 3, 4, 50, 20, 12};
    in.show();
    return 0;
}