#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    } 
};

int calculateHeight(Node* root)
{
    int h = 0;
    cout << "Start calc" << endl;
    if(root != nullptr)
    {
        cout << "Data " << root->data << endl;
        cout << "Calc left" << endl;
        int lH = calculateHeight(root->left);
        cout << "Left = " << lH << endl;
        cout << "Calculate Right" << endl;
        int rH = calculateHeight(root->right);
        cout << "Right = " << rH << endl;
        int higher = max(lH, rH);
        cout << "Higher = " << higher << endl;
        h = higher + 1;
        cout << "H = " << h << endl;
    }
    else
    {
        cout << "Node nullptr" << endl;
    }
    cout << "End calc" << endl;
    return h;
}

int main(int argc, char **argv)
{
    // creating a binary tree with 5 nodes
    Node *n1,*n2,*n3,*n4,*root, *n6, *n7, *n8;
    /*n8 = new Node(90, NULL, NULL);
    n6 = new Node(30, n8, NULL);
    n7 = new Node(70, NULL, NULL);*/
    n1 = new Node(5,n6,n7);
    n2 = new Node(7,NULL,NULL);
    n3 = new Node(6,n1,n2);
    n4 = new Node(9,NULL,NULL);
    root = new Node(3,n3,n4);

    int res = calculateHeight(root);
    cout << "Height of node = " << res << endl;
    return 0;
}