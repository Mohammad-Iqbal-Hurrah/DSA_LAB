/*                      WEEK 6 LAB:
        Topics: BST insertion, deletion, search, traversal.
        Problems: Build a BST and implement insertion, deletion, search.
        Visualize tree structure after operations.

*/
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// delete in BST
// helper function --> inOrder successor for the node having 2 children
node *inOrderSuccessor(node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

node *deleteNode(node *root, int key)
{
    if (root == NULL)
        return root;
    else if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            node *rightChild = root->right;
            delete root;
            return rightChild;
        }
        else if (root->right == NULL)
        {
            node *leftChild = root->left;
            delete root;
            return leftChild;
        }
        else
        {
            node *successor = inOrderSuccessor(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    return root;
}

// BST Insertion left < root < right
void BST_Insertion(node *&root, node *newNode)
{
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    if (newNode->data < root->data)
    {
        if (root->left == NULL)
        {
            root->left = newNode;
            return;
        }
        else
            BST_Insertion(root->left, newNode);
    }
    else if (newNode->data > root->data)
    {
        if (root->right == NULL)
        {
            root->right = newNode;
            return;
        }
        else
            BST_Insertion(root->right, newNode);
    }
    else
    {
        cout << "Duplicate data is not allowed in BST";
    }
}

class BST
{
public:
    node *root;
    BST()
    {
        root = NULL;
    }

    void insertData(int data)
    {
        node *newNode = new node(data);
        BST_Insertion(root, newNode);
    }

    // traversal
    void inOrder(node *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }

    // searching in BST
    node *search(node *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == key)
            return root;
        if (key < root->data)
            return search(root->left, key);
        if (key > root->data)
            return search(root->right, key);
        else
            return NULL;
    }
    void deleteData(int key)
    {
        root = deleteNode(root, key);
    }
};
int main()
{
    BST bt;
    bt.insertData(10);
    bt.insertData(5);
    bt.insertData(20);
    bt.insertData(2);
    bt.insertData(6);
    bt.insertData(15);
    bt.insertData(30);
    bt.inOrder(bt.root);
    node *result = bt.search(bt.root, 20);
    if (result != NULL)
        cout << "\nYes data is present in the tree";
    else
        cout << "\ndata is not present in the tree";

    bt.deleteData(5);

    cout<<"\nAfter Deletion\n";
    bt.inOrder(bt.root);

    return 0;
}