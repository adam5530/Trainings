#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char **argv)
{
    stack<int>st;
    //cout << st.top() << endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.top() << endl;
    st.emplace(5);
    st.emplace(6);
    cout << st.top() << endl;

    cout << "Iterating over the stack" << endl;
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}