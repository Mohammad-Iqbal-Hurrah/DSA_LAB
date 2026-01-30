//simple binary tree program and traversal techniques using recursion
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};
//inorder l.s.t --> root node --> r.s.t
void inOrder(node* root){
    if (root!=NULL)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
    
}

//preOrder root --> l.s.t --> r.s.t
void preOrder(node* root){
    if (root!=NULL)
    {
        cout<<root->data<<" ";
        inOrder(root->left);
        inOrder(root->right);
    }
    
}


//PostOrder l.s.t --> r.s.t --> root 
void postOrder(node* root){
    if (root!=NULL)
    {
        inOrder(root->left);
        inOrder(root->right);
        cout<<root->data<<" ";
    }
    
}

//free tree structure from memory-->memory management
void freeTree(node* root){
    if (root == NULL)
        return;
    freeTree(root->left); //clean left subtree
    freeTree(root->right); //clean right subtree

    delete root; //clean root 
    cout<<"\nMemory Cleaned\n";
}

int main(){
    node* root = new node(10);
    root->left = new node(50);
    root->right = new node(90);

    root->left->left = new node(26);
    root->left->right = new node(6);

    root->right->left = new node(105);
    root->right->right = new node(30);

    cout<<"InOrder Traversal:"<<endl;
    inOrder(root);

    cout<<"\nPreOrder Traversal:"<<endl;
    preOrder(root);

    cout<<"\nPostOrder Traversal:"<<endl;
    postOrder(root);

    //free tree memory
    freeTree(root);
}