#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<char, int>> convertString(string word)
{
    vector<pair<char, int>>result{};
    if(!word.empty())
    {
        unsigned int counter{1};
        for(unsigned int i = 0; i < word.size(); i++)
        {
            if(word[i] == word[i+1])
            {
                counter++;
            }
            else
            {
                pair<char, int> pr {make_pair<char, int>(move(word[i]), counter)};
                result.push_back(pr);
                counter = 1;
            }
        }
    }
    return result;
}

int main(int argc, char **argv)
{
    string word{"aaccaaddejjj"};
    cout << word << endl;
    auto result = convertString(word);
    for(auto &elem : result)
    {
        cout << elem.first << ": " << elem.second << " ";
    }
    cout << endl;
    return 0;
}