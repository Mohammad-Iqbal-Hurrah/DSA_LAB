#include <iostream>
using namespace std;
#define RED 1
#define BLACK 0
class node
{
public:
    int data;
    int color;
    node *left;
    node *right;
    node *parent;
    node(int data)
    {
        this->data = data;
        color = RED;
        left = right = parent = NULL;
    }
};
class redBlacTree
{
public:
    node *root;
    redBlacTree()
    {
        root = NULL;
    }

    // follow binary search tree insertion order
    void BST_Insertion(node *&root, node *newNode)
    {
        if (root == NULL) // when root points to NULL
        {
            root = newNode;
            return;
        }
        else if (newNode->data < root->data)
        {
            if (root->left == NULL)
            {
                root->left = newNode;
                newNode->parent = root;
            }
            else
                BST_Insertion(root->left, newNode);
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = newNode;
                newNode->parent = root;
            }
            else
                BST_Insertion(root->right, newNode);
        }
    }

    void insertData(int data)
    {
        node *newNode = new node(data);
        BST_Insertion(root, newNode);
    }

    //inorder traversal-->left-->root-->right
    void inorder(node* root){
        if (!root) 
            return;
        
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        
    }
};
int main()
{
    redBlacTree t;
    t.insertData(10);
    t.insertData(10);
    t.insertData(10);
    t.insertData(10);

    t.inorder(t.root);
    return 0;
}