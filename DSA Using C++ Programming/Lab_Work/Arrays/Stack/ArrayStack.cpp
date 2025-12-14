/*Implement stack using arrays*/
#include<iostream>
using namespace std;
class myStack{
    int* arr;
    int capacity;
    int top;
    public:
        myStack(int cap){
            capacity = cap;
            top = -1;
            arr = new int[capacity];
        }

void push(int data){
    if (top==capacity-1)
    {
        cout<<"OverFlow\n";
        return;
    }
    arr[++top] = data;
    cout<<data<<" Inserted\n"; 
}

int pop(){
    if (top==-1)
    {
        cout<<"\nUnderFlow\n";
        return -1;
    }
    int data = arr[top--];
    return data;
}

int peek(){
    if (top==-1)
    {
        cout<<"\nUnderFlow\n";
        return -1;
    }
    int data = arr[top];
    return data;
}
};
int main(){
    myStack st(5);
    st.push(7);
    st.push(2);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    cout<<st.peek();
    cout<<st.pop();
    cout<<st.pop();
    cout<<st.pop();
    cout<<st.pop();
    return 0;
}