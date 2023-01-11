#include <iostream>

using namespace std;

int val(int value)
{
    value++;
    return value;
}

int ref(int &reference)
{
    reference++;
    return reference;
}

int ptr(int *pointer)
{
    (*pointer)++;
    return *pointer;
}

int constPtr(const int *ptr)
{
    //(*ptr)++; -> error, read only
    *ptr++;
    return *ptr;
}

int ptrConst(int *const ptr)
{
    (*ptr)++;
    //*ptr++; -> error, cannot increment read only
    return *ptr;
}

void printParams(int val, int &ref, int *ptr)
{
    cout << "Address of val " << val << " is " << &val << endl;
    cout << "Address of ref " << ref << " is " << &ref << endl;
    cout << "Address of ptr " << *ptr << " is " << ptr << " and address of pointer " << &ptr << endl;
}

void printPtr(int *ptr, int *&ptrRef)
{
    cout << "Address of val by ptr " << *ptr << " is " << ptr << " and addres of pointer " << &ptr << endl;
    cout << "Address of val by ref ptr " << *ptrRef << " is " << ptrRef << " and addres of referenced pointer " << &ptrRef << endl;
}

int main(int argc, char **argv)
{
    int value = 10;
    int a = val(value);
    cout << "value " << value << " a " << a << endl;

    int reference = 10;
    int b = ref(reference);
    cout << "reference " << reference << " b " << b << endl;

    int *pointer = new int(10);
    int c = ptr(pointer);
    cout << "ptr " << *pointer << " c " << c << endl;
    delete pointer;
    pointer = nullptr;

    int *pointer2 = new int[2];
    pointer2[0] = 10;
    pointer2[1] = 30;
    int d = constPtr(pointer2);
    cout << "ptr2 " << *pointer2 << " d " << d << endl;
    delete []pointer2;

    int *pointer3 = new int(199);
    int e = ptrConst(pointer3);
    cout << "ptr3 " << *pointer3 << " e " << e << endl;
    delete pointer3;
    pointer3 = nullptr;

    cout << "========== print params ===========" << endl;
    int val = 100;
    int z = 300;
    int *ptr = &z;
    cout << "Before method printParams" << endl;
    cout << "Address of val " << val << " is " << &val << endl;
    cout << "Address of ptr " << *ptr << " is " << ptr << " and address of pointer " << &ptr << endl;
    cout << "Now let's print params in method" << endl;
    printParams(val, val, ptr);

    cout << "========== print pointers ========" << endl;
    int val2 = 400;
    int *ptr2 = &val2;
    cout << "Before method printPtr" << endl;
    cout << "Addres of val2 by ptr2 " << *ptr2 << " is " << ptr2 << " and address of pointer2 " << &ptr2 << endl;
    cout << "Now let's print pointers in method" << endl;
    printPtr(ptr2, ptr2);
    return 0;
}