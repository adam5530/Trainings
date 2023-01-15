#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree
{
private:
    Node *root;
public:
    BinaryTree() : root(nullptr) {}
    void addNode(int data)
    {
        Node *newNode = new Node(data);
        if(root == nullptr)
        {
            root = newNode;
        }
        else
        {
            Node *focusNode = root;
            Node *parent;
            while(true)
            {
                parent = focusNode;
                if(data < focusNode->data)
                {
                    focusNode = focusNode->left;
                    if(focusNode == nullptr)
                    {
                        parent->left = newNode;
                        return;
                    }
                }
                else
                {
                    focusNode = focusNode->right;
                    if(focusNode == nullptr)
                    {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }
    void preorderTraversal(Node *focuseNode)
    {
        if(focuseNode != nullptr)
        {
            cout << focuseNode->data << " ";
            preorderTraversal(focuseNode->left);
            preorderTraversal(focuseNode->right);
        }
    }
    Node* getRoot() const { return root; }
};

int main(int argc, char **argv)
{
    BinaryTree tree;
    tree.addNode(39);
    tree.addNode(68);
    tree.addNode(90);
    tree.addNode(30);
    tree.addNode(50);
    tree.addNode(10);
    tree.addNode(70);

    tree.preorderTraversal(tree.getRoot());
    cout << endl;
    cout << tree.getRoot()->data << endl;
    return 0;
}