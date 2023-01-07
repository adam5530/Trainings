#include <iostream>
#include <algorithm>

using namespace std;

bool validBraces(string word)
{
    bool result = true;
    int counterMatched{0};
    for(int i = 0; i < word.size(); i++)
    {
        if(word[i] == '{')
        {
            for(int j = i+1; j < word.size(); j++)
            {
                if(word[j] == '}' and (j-i)%2 == 0)
                {
                    result = false;
                    break;
                }
                else if(word[j] == '}' and (j-i)%2 != 0)
                {
                    break;
                }
            }
        }
        if(word[i] == '[')
        {
            for(int j = i+1; j < word.size(); j++)
            {
                if(word[j] == ']' and (j-i)%2 == 0)
                {
                    result = false;
                    break;
                }
                else if(word[j] == ']' and (j-i)%2 != 0)
                {
                    break;
                }
            }
        }
        if(word[i] == '(')
        {
            for(int j = i+1; j < word.size(); j++)
            {
                if(word[j] == ')' and (j-i)%2 == 0)
                {
                    result = false;
                    break;
                }
                else if(word[j] == ')' and (j-i)%2 != 0)
                {
                    break;
                }
            }
        }
    }
    return result;
}

int main(int argc, char **argv)
{
    string word {"{[]}({[]})[]"};
    cout << validBraces(word) << endl;
    return 0;
}