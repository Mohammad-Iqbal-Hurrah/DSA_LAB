
#include <iostream>
using namespace std;

#define RED 1
#define BLACK 0

class node {
public:
    int data;
    int color;
    node *left, *right, *parent;

    node(int x) {
        data = x;
        color = RED;
        left = right = parent = NULL;
    }
};

class RBTree {
public:
    node* root;

    RBTree() {
        root = NULL;
    }

    /* ------------------ ROTATIONS ------------------ */
    /*
    | Case | Steps                          |
| ---- | ------------------------------ |
| LL   | rightRotate(G)                 |
| LR   | leftRotate(P) → rightRotate(G) |
| RR   | leftRotate(G)                  |
| RL   | rightRotate(P) → leftRotate(G) |
*/

    void leftRotate(node* x) {
        node* y = x->right;
        x->right = y->left;

        if (y->left)
            y->left->parent = x;

        y->parent = x->parent;

        if (!x->parent)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rightRotate(node* x) {
        node* y = x->left;
        x->left = y->right;

        if (y->right)
            y->right->parent = x;

        y->parent = x->parent;

        if (!x->parent)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    /* ------------------ INSERT ------------------ */

    void BST_Insert(node*& root, node* z) {
        if (!root) {
            root = z;
            return;
        }
        if (z->data < root->data) {
            if (!root->left) {
                root->left = z;
                z->parent = root;
            } else BST_Insert(root->left, z);
        } else {
            if (!root->right) {
                root->right = z;
                z->parent = root;
            } else BST_Insert(root->right, z);
        }
    }

    void fixInsertion(node* z) {
        while (z != root && z->parent->color == RED) {
            node* p = z->parent;
            node* g = p->parent;

            if (p == g->left) {
                node* u = g->right;

                if (u && u->color == RED) {
                    p->color = BLACK;
                    u->color = BLACK;
                    g->color = RED;
                    z = g;
                } else {
                    if (z == p->right) {
                        leftRotate(p);
                        z = p;
                        p = z->parent;
                    }
                    rightRotate(g);
                    p->color = BLACK;
                    g->color = RED;
                }
            } else {
                node* u = g->left;

                if (u && u->color == RED) {
                    p->color = BLACK;
                    u->color = BLACK;
                    g->color = RED;
                    z = g;
                } else {
                    if (z == p->left) {
                        rightRotate(p);
                        z = p;
                        p = z->parent;
                    }
                    leftRotate(g);
                    p->color = BLACK;
                    g->color = RED;
                }
            }
        }
        root->color = BLACK;
    }

    void insert(int data) {
        node* z = new node(data);
        BST_Insert(root, z);
        fixInsertion(z);
    }

    /* ------------------ SEARCH ------------------ */

    node* search(node* root, int key) {
        if (!root || root->data == key)
            return root;
        if (key < root->data)
            return search(root->left, key);
        return search(root->right, key);
    }

    /* ------------------ DELETION ------------------ */

    node* successor(node* x) {
        while (x->left)
            x = x->left;
        return x;
    }

    void fixDoubleBlack(node* x) {
        if (x == root)
            return;

        node* p = x->parent; //parent
        node* s = (x == p->left) ? p->right : p->left; //sibling 

        if (!s) {
            fixDoubleBlack(p);
        }
        else if (s->color == RED) {
            s->color = BLACK;
            p->color = RED;
            if (s == p->left)
                rightRotate(p);
            else
                leftRotate(p);
            fixDoubleBlack(x);
        }
        else {
            if ((s->left && s->left->color == RED) ||
                (s->right && s->right->color == RED)) {

                if (s == p->left) {
                    if (s->left && s->left->color == RED) {
                        s->left->color = p->color;
                        p->color = BLACK;
                        rightRotate(p);
                    } else {
                        s->right->color = p->color;
                        leftRotate(s);
                        rightRotate(p);
                    }
                } else {
                    if (s->right && s->right->color == RED) {
                        s->right->color = p->color;
                        p->color = BLACK;
                        leftRotate(p);
                    } else {
                        s->left->color = p->color;
                        rightRotate(s);
                        leftRotate(p);
                    }
                }
            } else {
                s->color = RED;
                if (p->color == BLACK)
                    fixDoubleBlack(p);
                else
                    p->color = BLACK;
            }
        }
    }



/*deleteNode(key)
│
├── search(key)
│
├── BST-style delete (u choose hota hai)
│
├── if deleted node was RED → DONE
│
└── if deleted node was BLACK
     │
     ├── if RED child → recolor
     │
     └── else → fixDoubleBlack()
*/
    void deleteNode(int key) {
        node* v = search(root, key);
        if (!v) {
            cout<<"\n Node Not Found \n";
            return;
        }

        node* u;
        int uvColor;

        if (!v->left || !v->right) {
            u = v;
        } else {
            u = successor(v->right);
            v->data = u->data;
        }

        node* child = u->left ? u->left : u->right;
        uvColor = u->color;

        if (child)
            child->parent = u->parent;

        if (!u->parent)
            root = child;
        else if (u == u->parent->left)
            u->parent->left = child;
        else
            u->parent->right = child;

            //decide fixdeletion
        if (uvColor == BLACK) {
            if (child && child->color == RED)
                child->color = BLACK;
            else
                fixDoubleBlack(child ? child : u->parent);
        }

        delete u;
    }

    /* ------------------ TRAVERSAL ------------------ */

    void inorder(node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << "(" << (root->color ? "R" : "B") << ") ";
        inorder(root->right);
    }
};

/* ------------------ MAIN ------------------ */

int main() {
    RBTree t;

    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(15);
    t.insert(25);

    node* destin = t.search(t.root,30);

    cout << "Inorder before deletion:\n";
    
    cout<<destin->data;

    t.deleteNode(10);
    t.deleteNode(25);

    cout << "\n\nInorder after deletion:\n";
    t.inorder(t.root);

    return 0;
}
