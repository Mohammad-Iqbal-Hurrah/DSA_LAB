/*implement Queue using array*/
#include<iostream>
using namespace std;
class myQueue{
    int* arr;
    int capacity;
    int size;
    public:
        myQueue(int cap){
            capacity = cap;
            size = 0;
            arr = new int[capacity];
        }
        void enqueue(int data){
            if (size == capacity){
                cout<<"OverFlow\n";
                return;
            }
            else
                arr[size++] = data;
            cout<<data<<" Inserted \n";
        }
        int dequeue(){
            if (size == 0){
                cout<<"UnderFlow";
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

        int getFront(){
            if (size == 0){
                cout<<"UnderFlow";
                return -1;
            }
            return arr[0];
        }
};
int main(){
    myQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<q.getFront()<<endl;//10
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getFront()<<endl;//30
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}