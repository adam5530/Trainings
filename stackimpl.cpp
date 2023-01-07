#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

template<class T> class Stack
{
private:
    T *arr;
    size_t size;
    size_t capacity;
public:
    Stack()
    {
        size = 1;
        capacity = 1;
        arr = new T[size];
    }
    void push(const T &obj)
    {
        if(isEmpty())
        {
            size = 1;
            capacity = 1;
            arr = new T[size];
        }
        if(size == 1 and capacity == 1)
        {
            arr[0] = obj;
            capacity++;
        }
        else
        {
            if(size < capacity)
            {
                T *temp = new T[capacity];
                copy(arr, arr+size, temp);
                delete[] arr;
                arr = new T[capacity++];
                copy(temp, temp+size, arr);
                delete[] temp;
                arr[size++] = obj;
            }
        }
    }
    void pop()
    {
        if(size >= 2)
        {
            size--;
            capacity--;
            T *temp = new T[size];
            copy(arr, arr+size, temp);
            delete[] arr;
            arr = new T[size];
            copy(temp, temp+size, arr);
            delete[] temp;
        }
        else
        {
            delete[] arr;
            size = 0;
            capacity = 0;
        }
    }
    bool isEmpty() const { return size == 0; }
    T top() const
    {
        if(isEmpty())
            throw invalid_argument("Size must be at least 1");
        return arr[size-1];
    }
};

int main(int argc, char **argv)
{
    Stack<int>st;
    cout << "Push elements " << endl;
    st.push(1);
    cout << st.top() << endl;
    st.push(2);
    cout << st.top() << endl;
    st.push(3);
    cout << st.top() << endl;

    cout << "Pop elements " << endl;

    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    if(!st.isEmpty())
        cout << st.top() << endl;

    cout << "Push elements again " << endl;
    st.push(55);
    cout << st.top() << endl;
    st.push(123);
    cout << st.top() << endl;
    return 0;
}