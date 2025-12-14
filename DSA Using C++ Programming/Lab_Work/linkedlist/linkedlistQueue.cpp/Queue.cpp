/*Implement queue using linkedlist*/
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int x){
        data = x;
        next = nullptr;
    }
};

class myQueue{
    node* front;
    node* rear;
    public:
        myQueue(){
            front = nullptr;
            rear = nullptr;
        }
        void enqueue(int x){
            node* newNode = new node(x);
            // if queue is empty (front == nullptr) set both front and rear
            if (front == nullptr)
            {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
            cout<<x<<" Inserted\n";
        }

        int dequeue(){
            // empty queue when front is nullptr
            if (front == nullptr)
            {
                cout<<"Queue is empty\n";
                return -1;
            }
            node* temp = front;
            int data = temp->data;
            front = front->next;
            if (front == nullptr)
                rear = nullptr;
            delete temp;
            return data;
        }

        int getFront(){
            // empty queue when front is nullptr
            if (front == nullptr)
            {
                cout<<"Queue is empty\n";
                return -1;
            }
            return front->data;
        }
};
int main(){
    myQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<"Peek"<<q.getFront()<<endl;
    q.enqueue(40);
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();
     cout<<"Peek"<<q.getFront()<<endl;
    cout<<q.dequeue();
    return 0;
}