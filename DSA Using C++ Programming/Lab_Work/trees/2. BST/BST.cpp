/*binary search tree
count number of nodes and leaves in it 
find min and max 
preOrder, inOrder and PostOrder traversal
Searching */

#include<iostream>
using namespace std;
class node {
    public:
        int data;
        node* left;
        node* right;
        node(int x){
            cout<<"\nInserting "<<x<<endl;
            data = x;
            left = right = NULL;
        }
};

//insert in BST
node* insert(node* root, int val){
    if (root==NULL)
        return new node(val);
    if (val<root->data)
        root->left = insert(root->left,val); //recursively find the correct position on left side 
    else if (val>root->data)
    root->right = insert(root->right,val); //recursively find the correct position on right side 
return root;
}

//inorder traversal --> gives sorted data 
void inOrder(node* root){
    if (root !=NULL)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
    
}

//Preorder traversal
void preOrder(node* root){
    if (root !=NULL)
    {
        cout<<root->data<<" ";
        inOrder(root->left);
        inOrder(root->right);
    }
    
}

//PostOrder traversal
void postOrder(node* root){
    if (root !=NULL)
    {
        inOrder(root->left);
        inOrder(root->right);
        cout<<root->data<<" ";
    }
    
}

//count total number of nodes in a BST 
int countNodes(node* root){
    if (root)
    {
        int l = countNodes(root->left);
        int r = countNodes(root->right);
        return (1+l+r);
    }
    
}


//count total number of leaves in a BST 
int countLeaves(node* root){
    if (root)
    {
        if (root->left == NULL and root->right == NULL)
            return 1;
        else
        return countLeaves(root->left) + countLeaves(root->right);
    }
    
    
}


//find minimum -->left extreme node will be the minimum
int findMin(node*root){
    while (root->left)
    {
        root = root->left;
    }
    return root->data;
}

//find minimum -->right extreme node will be the maximum
int findMax(node*root){
    while (root->right)
    {
        root = root->right;
    }
    return root->data;
}


void display(node* root){
    // cout<<"\nDisplaying BST:\n";
    if (root)
    {
        cout<<root->data<<" ";
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
    
}

//height of a node 
int height(node* root){
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (1 + max(leftHeight,rightHeight));
    
}

//depth of a tree
int depth(node* root,int key){
    int depth = 0;
    while (root != NULL)
    {
        if (key == root->data)
            return depth;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
        depth++;
    }
    return -1; //if key is not foud
    
}


//find minimum node
node* findMinNode(node* root){
    while (root->left != NULL)
        root = root->left;
    return root;
    
}


//deletion cases
node* deleteNode(node* root, int key){
    if (root == NULL)
        return root;
    //search
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right,key);
    else{

        cout<<"\nCase1 ";
        //CASE 1: leaf node case-->direct delete
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // CASE 2: Node with 1 child-->replace node by its child
        else if (root->left == NULL) //right child is present
        {
            cout<<"\nCase2 ";
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) //left child is present 
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        
        // CASE 3: Node with 2 chilren
        else{
            cout<<"\nCase3 ";
            node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
    return root;
}

//Searching in BST
node* searchKey(node *root, int key)
{
    if (root == NULL || root->data == key) // no node in tree or root->data = key
        return root;

    if (key < root->data)
        return searchKey(root->left, key); // recursively search in left half and return when found
    else
    return searchKey(root->right, key); // recursively search in right half and return when foud
}
  

int main(){
    node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
       root = insert(root,arr[i]);
    }
    cout<<"\nInOrder Traversal: "<<endl;
    inOrder(root);

    cout<<"\n\nPreOrder Traversal: "<<endl;
    preOrder(root);
    cout<<"\n\nPoseOrder Traversal: "<<endl;
    postOrder(root);


    int totalNodes = countNodes(root); //count number of nodes in BST
    cout<<"\n\nTotal number of nodes: "<<totalNodes;

    int totalLeaves = countLeaves(root); //count number of nodes in BST
    cout<<"\n\nTotal number of leaves: "<<totalLeaves;

    int minNode = findMin(root);
    cout<<"\n\nMinimum Node Data:"<<minNode;


    int maxNode = findMax(root);
    cout<<"\n\nMax Node Data:"<<maxNode;

    
    cout<<"\n\nDisplay Function"<<endl;
    display(root); 

    //height of a trees
    int hiet = height(root);
    cout<<"\n\nHeight of tree: "<<hiet;

    //depth of a node
    int dpth = depth(root,50);
    cout<<"\n\nDepth of Root: "<<dpth;


    //Delete node
    node* N = deleteNode(root,80);
    cout<<"\n\nDeleted Node Data: "<<N->data<<endl;

    //Searching 
    node *result = searchKey(root, 45);  
    if (result != NULL) 
        cout << "\nKey found\n";
    else
        cout << "\nKey not found\n";
    

    return 0;
}