/*Implement stack using array*/
#include <iostream>
using namespace std;
class stack
{
    int top;
    int size;
    int *arr;
    int capacity;

public:
    stack()
    {
        top = -1;
        capacity = 4;
        size = 0;
        arr[capacity];
    }
    bool isEmpty()
    {
        if (top < 0 || size == 0)
        {
            return 1;
        }
        else
            return 0;
    }
    bool isFull()
    {
        if (size >= capacity || top >= capacity - 1)
        {
            return 1;
        }
        else
            return 0;
    }
    void display()
    {
        if (isEmpty())
        {
                cout<<"Stack is empty ";
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        
    }
    void insert(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow";
            return;
        }
        top += 1;
        arr[top] = data;
        size += 1;
    }

    int dlt()
    {
        if (isEmpty())
        {
            cout << "Stack underflow";
            // return;
        }
        int data = arr[top];
        top--;
        size -= 1;

        return data;
    }
};
int main()
{
    stack s;
    // cout << s.isEmpty() << endl;
    // cout << s.isFull() << endl;
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    // s.insert(60); //stack overflow as capacity of the stack is 4 elements
    s.display();
    cout << s.dlt() << endl;
    cout << s.dlt() << endl;
    cout << s.dlt() << endl;
    s.display();
    cout << s.dlt() << endl;
    s.display();
    return 0;
}