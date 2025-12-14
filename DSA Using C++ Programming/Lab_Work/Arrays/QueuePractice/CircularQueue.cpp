#include<iostream>
using namespace std;
class circularQueue{
    int* arr;
    int size,capacity,front;
public:
circularQueue(int cap){
    capacity = cap;
    arr = new int[capacity];
    size = 0;
    front = 0;
}
void enqueue(int data){
    if (size == capacity)
    {
        cout<<"Overflow...\n";
        return;
    }
    int rear = (front+size)%capacity;
    arr[rear] = data;
    cout<<"data pushed on to the queue\n";
    size++;
}

int dequeue(){
    if (size == 0)
    {
        cout<<"underflow...\n";
        return -1;
    }
    int data = arr[front];
    front = (front+1)%capacity;
    size--;
    return data;
}

};
int main(){
    circularQueue cq(4);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cout<<"Dequed element is: "<<cq.dequeue()<<endl;
    cout<<"Dequed element is: "<<cq.dequeue()<<endl;
    cout<<"Dequed element is: "<<cq.dequeue()<<endl;
    cout<<"Dequed element is: "<<cq.dequeue()<<endl;
    cout<<"Dequed element is: "<<cq.dequeue()<<endl;
    return 0;
}