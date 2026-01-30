/* Everything about AVL Trees in DSA 

Created AVL Tree node structure with data, pointers, and height.

Implemented height calculation for each node.

Calculated balance factor to check tree balance.

Implemented AVL rotations:

Left-Left (LL) Rotation

Right-Right (RR) Rotation

Left-Right (LR) Rotation

Right-Left (RL) Rotation

Performed insertion in AVL Tree with automatic balancing.

Performed deletion in AVL Tree including:

Deletion of leaf node

Deletion of node with one child

Deletion of node with two children using inorder successor

Rebalanced the AVL Tree after deletion.

Displayed the AVL Tree using inorder traversal.

Implemented searching operation in AVL Tree.
*/



#include <iostream>
using namespace std;

// AVL Tree Node Structure
class node
{
public:
    int data;
    node *left;
    node *right;
    int height;
    // Constructor to initialize the node and height
    node(int x)
    {
        cout << "\nInserting " << x << endl;
        data = x;
        left = right = NULL;
        height = 1;
    }
};

// get height of a node
int height(node *n)
{
    if (n == NULL)
        return 0;
    else
        return n->height;
}

// Balancing factor for a node-->height of L.S.T - R.S.T
int getBalancingFactor(node *n)
{
    if (n == NULL)
        return 0;
    else
        return (height(n->left) - height(n->right));
}

// Rotations
//  1. LL Left Heavy Fix --> Rotate right
node *rightRotate(node *A)
{
    node *B = A->left;
    node *C = B->right;

    B->right = A;
    A->left = C;

    A->height = max(height(A->left), height(A->right)) + 1; // necesary because A gets dislocated and C is at its original place
    B->height = max(height(B->left), height(B->right)) + 1;

    return B; // new root
}

// 2. RR Right Heavy Fix--> Rotate Left
node *leftRotate(node *A)
{
    node *B = A->right;
    node *C = B->left;

    B->left = A;
    A->right = C;

    A->height = max(height(A->left), height(A->right)) + 1; // necesary because A gets dislocated and C is at its original place
    B->height = max(height(B->left), height(B->right)) + 1;

    return B;
}

// Insert in AVL Tree --> Normal BST Insertion
node *insert(node *root, int key)
{

    // Normal BST insert
    if (root == NULL)
        return new node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // duplicates not allowed

    // Update height
    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalancingFactor(root);

    // LL
    if (balance > 1 && key < root->left->data)
        return rightRotate(root); // Left Heavy BST

    // RR
    if (balance < -1 && key > root->right->data)
        return leftRotate(root); // Right Heavy BST

    // LR
    if (balance > 1 && key > root->left->data)
    {                                        // Left Right Degenerated BST
        root->left = leftRotate(root->left); // 1. Rotate Lesft
        return rightRotate(root);            // 2. Rotate Right
    }

    // RL
    if (balance < -1 && key < root->right->data)
    {                                           // Right Left Degenerated BST
        root->right = rightRotate(root->right); // 1. Rotate Right
        return leftRotate(root);                // 2. Rotate Right
    }

    return root;
}

// Deletion cases --> for InOrder Successor -->helper Function
// when a parent has 2 children --> will be used for Case3
node *minValueNode(node *root)
{
    node *curr = root;
    while (curr->left != NULL) // Find Left Extreme
        curr = curr->left;
    return curr; // return left extreme node
}

node *deleteNode(node *root, int key)
{

    // STEP 1: Normal BST deletion
    if (root == NULL)
        return root;

    // Search For a Node
    // go left
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // go right
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node Found and now perform 3 cases of deletion
        //  case 1. leaf node
        //  case 2. Node with 1 child
        //  case 3. Node with 2 children

        // CASE 1 & 2: 0 or 1 child
        if (root->left == NULL || root->right == NULL)
        {
            node *temp = root->left ? root->left : root->right; // storing either left or right child in temp node

            if (temp == NULL) // no child
            {
                temp = root;
                root = NULL;
            }
            else // one child
            {
                *root = *temp; // replace node with child node either left or right child
            }
            delete temp;
        }

        // CASE 3: two children
        else
        {
            // inorder successor
            node *temp = minValueNode(root->right); // go right and replace with left extreme
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data); // Delete that left leaf node which replaced root node
        }
    }

    // Check for rotations --> Tree may become unballanced after deletion
    //  If tree had only one node
    if (root == NULL)
        return root;

    // STEP 2: Update height
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: Check balance
    int balance = getBalancingFactor(root);

    // LL
    if (balance > 1 && getBalancingFactor(root->left) >= 0)
        return rightRotate(root);

    // LR
    if (balance > 1 && getBalancingFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalancingFactor(root->right) <= 0)
        return leftRotate(root);

    // RL
    if (balance < -1 && getBalancingFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder Traversal
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Searching
node* search(node *root, int key)
{
    if (root == NULL || root->data == key) // no node in tree or root->data = key
        return root;

    if (key < root->data)
        return search(root->left, key); // recursively search in left half and return when found
    else
        return search(root->right, key); // recursively search in right half and return when foud
}

int main()
{
    node *root = NULL;

    int arr[] = {10, 20, 30, 40, 50, 25};

    for (int i = 0; i < 6; i++)
        root = insert(root, arr[i]);

    cout << "Inorder traversal: ";
    inorder(root);

    int h = height(root); // height of root
    cout << "\n Height of root: " << h << endl;

    int BF = getBalancingFactor(root); // Balancing Factor of Root
    cout << "\nBalancing Factor of Root:" << BF << endl;

    root = deleteNode(root, 10); // delete leaf node
    root = deleteNode(root, 40); // delete node with 1 child --> right child = 50
    root = deleteNode(root, 30); // delete node with 2 children --> left = 20 , right = 50
    cout << "Inorder traversal After Deletion: ";
    inorder(root);

    //Searching 
    node *result = search(root, 45);  
    if (result != NULL) 
        cout << "\nKey found\n";
    else
        cout << "\nKey not found\n";

    return 0;
}
