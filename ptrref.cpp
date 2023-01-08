#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    cout << "Pointer " << endl;
    int x = 10;
    int *ptr = &x;
    cout << "Address of x by ptr " << ptr << " and value of x from ptr " << *ptr << endl;
    cout << "Address of x by x   " << &x << " and value of x from x " << x << endl;
    cout << "Addres of ptr " << &ptr << endl;
    int w = 50;
    ptr = &w;
    cout << "Move pointer to another variable" << endl;
    cout << "Address of w by ptr " << ptr << " and value of w from ptr " << *ptr << endl;
    cout << "Address of w by w   " << &w << " and value of w from w " << w << endl;
    ptr = nullptr;

    cout << "Reference" << endl;
    int y = 20;
    int &ref = y;
    cout << "Address of y by ref " << &ref << " and value of y from ref " << ref << endl;
    cout << "Address of y by y   " << &y << " and value of y from y " << y << endl;
    int z = 30;
    ref = z;
    cout << "Reference 2" << endl;
    cout << "Address of z by ref " << &ref << " and value of z from ref " << ref << endl;
    cout << "Address of z by z   " << &z << " and value of z from z " << z << endl;
    cout << "Address of y by y   " << &y << " and value of y from y " << y << endl;


    cout << "Const int *pointer " << endl;
    int arr[2] = {1, 5};
    const int* pointer = &arr[0];
    //const int* <const -> error(cannot move pointer to another variable)> pointer = &arr[0];
    *pointer++;
    cout << "Address of arr[1] " << pointer << " and value of arr[1] " << *pointer << endl;
    //(*pointer)++; -> error(cannot change value by pointer)

    cout << "int * const pointer " << endl;
    int* const pointer2 = &arr[0];
    (*pointer2)++;
    //*pointer++; error(cannot change read only variable);
    cout << "Address of arr[0] " << pointer2 << " and value of arr[0] " << *pointer2 << endl;

    return 0;
}