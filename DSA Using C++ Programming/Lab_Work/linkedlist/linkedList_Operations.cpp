#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int element)
    {
        data = element;
        next = NULL;
    }
};
void insertAtStart(node *&head, int data)
{
    node *newnode = new node(data);
    newnode->next = head;
    head = newnode;
}

void insertAtindex(node *&head, int index, int data)
{
    // insert at head when index <= 0
    if (index <= 0)
    {
        insertAtStart(head, data);
        return;
    }
    // if list is empty, inserting any positive index is equivalent to inserting at start
    if (head == NULL)
    {
        insertAtStart(head, data);
        return;
    }

    node *temp = head;
    int count = 0;
    // move temp to the (index-1)-th node or to the last node if index is out of bounds
    while (temp->next != NULL && count < index - 1)
    {
        temp = temp->next;
        count++;
    }

    // now temp is the node after which we should insert
    node *newNode = new node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd(node *&head, int data)
{
    cout<<"Insert at end function.\n";
    if (head == NULL)
    {
        insertAtStart(head, data);
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // temp->next = new node(data);
    node* newNode = new node(data);
    temp->next = newNode;
    newNode->next = NULL;
}
void changeNode(node *head, int data, int index)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = head;
    int count = 0;
    while (temp != NULL && count < index)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        cout << "Index out of bounds" << endl;
        return;
    }
    temp->data = data;
}
void display(node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        // return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        // if(temp->next)
        // cout << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int dltAtStart(node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return -1;
    }
    node *temp = head;
    int data = temp->data;
    head = head->next;
    delete temp;
    return data; // return deleted element
}

int dltAtEnd(node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return -1;
    }
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    int data = temp->next->data;
    temp->next = NULL;
    delete temp->next;
    return data; // return deleted element
}
int dltAtIndex(node *&head)
{
    int index;
    cout << "Enter the index to delete: ";
    cin >> index;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return -1; // Indicating failure
    }
    if (index == 0)
    {
        return dltAtStart(head);
    }
    node *temp = head;
    int count = 0;
    while (temp->next != NULL && count < index )
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        cout << "Index out of bounds" << endl;
        return -1; // Indicating failure
    }
    node *dltNode = temp->next;
    int data = dltNode->data;
    temp->next = dltNode->next;
    delete dltNode;
    return data; // return deleted element
}
int main()
{
    node *head = NULL;
    insertAtStart(head, 10);
    insertAtEnd(head, 20);
    insertAtindex(head, 1, 15); // List: 20->15->10->30
    changeNode(head, 30, 0);    // List: 20->15->25->30
    cout<<dltAtStart(head)<<endl; // List: 15->25->30
    cout<<dltAtEnd(head)<<endl; // List: 15->25
    cout<<dltAtIndex(head)<<endl;
    display(head);
    return 0;
}