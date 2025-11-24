//Queue implementation using arrays.
#include<iostream>
using namespace std;
class staticQueue{
    int* arr;
    int size;
    int capacity;
    public:
    staticQueue(int cap){
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }
    bool isFull(){
        return size==capacity;
    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(int data){
        if (isFull())
        {
            cout<<"Overflow...";
            return;
        }
        arr[size++] = data;
        cout<<data<<" pushed into the queue\n";
    }

    int dequeue(){
        if (isEmpty())
        {
            cout<<"Underflow...";
            return -1;
        }
        int data = arr[0];
        for (int i = 1; i < size; i++)
        {
            arr[i-1] = arr[i];
        }
        size--;
        return data;
    }
    int sizeOfQueue(){
        return size;
    }
    int peek(){
        return arr[0];
    }
};
int main(){
    staticQueue sq(4);
    sq.enqueue(1);
    sq.enqueue(3);
    sq.enqueue(5);
    sq.enqueue(7);
    cout<<"Size of the queue is: "<<sq.sizeOfQueue()<<endl;
    cout<<"Element to be deleted: "<<sq.peek()<<endl;
    cout<<sq.dequeue()<<" Dequed\n";
    cout<<sq.dequeue()<<" Dequed\n";
    cout<<"Size of the queue is: "<<sq.sizeOfQueue()<<endl;
    cout<<"Element to be deleted: "<<sq.peek();
    return 0;
}