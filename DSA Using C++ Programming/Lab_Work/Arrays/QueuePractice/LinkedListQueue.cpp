#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int element){
        data = element;
        next = nullptr;
    }
};

class queue{
    node* front;
    node* rear;
public:
    queue(){
        front = rear = nullptr;
    }
    bool isEmpty(){
        return front == nullptr;
    }
    void enqueue(int element){
        node* newNode = new node(element);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue(){
        if (isEmpty())
        {
           cout<<"underflow...";
           return -1;
        }
        node* temp = front;
        int data = temp->data;
        front = front->next;
        if (front==nullptr)
        {
            rear = nullptr;
        }
        delete temp;
        return data;
    }
};
int main(){
    queue qll;
    qll.enqueue(10);
    qll.enqueue(20);
    qll.enqueue(30);
    qll.enqueue(40);
    cout<<"Element popped: "<<qll.dequeue()<<endl;
    cout<<"Element popped: "<<qll.dequeue()<<endl;
    cout<<"Element popped: "<<qll.dequeue()<<endl;
    cout<<"Element popped: "<<qll.dequeue()<<endl;
    cout<<"Element popped: "<<qll.dequeue()<<endl;
    return 0;
}