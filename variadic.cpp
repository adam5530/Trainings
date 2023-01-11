#include <iostream>

using namespace std;

void print()
{
    cout << "I am empty function" << endl;
}

template <typename T, typename... Types>
void print(T var1, Types... varN)
{
    cout << var1 << "->>>>>>>>>>>>>" << endl;
    print(varN...);
}

void fprint(const char *format)
{
    cout << format;
}
template <typename T, typename... Types>
void fprint(const char *format, T value, Types... args)
{
    for(; *format != '\0'; format++)
    {
        if(*format == '%')
        {
            cout << value;
            fprint(format+1, args...);
            return;
        }
        cout << *format;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    //print(1, 2, 3, 4, "Pass as many args as you want");

    fprint("%s word% %\n", "Hello", '!', 123);
    fprint("This is number % \n", 2222);
    return 0;
}