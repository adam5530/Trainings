#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrom(string word)
{
    transform(word.begin(), word.end(), word.begin(),
    [](char c)
    {
        return tolower(c);
    }
    );
    string palindrom{word};
    reverse(palindrom.begin(), palindrom.end());
    return (word == palindrom) ? true : false;
}

int main(int argc, char **argv)
{
    cout << isPalindrom("JJejj") << endl;
    return 0;
}