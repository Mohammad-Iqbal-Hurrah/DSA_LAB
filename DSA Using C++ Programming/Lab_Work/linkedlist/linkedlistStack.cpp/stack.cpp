/*Implement stack using linkedlist*/
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
class stack{
    node* top;
    public:
        stack(){
            top = nullptr;
        }
        void push(int x){
            node* newNode = new node(x);
            newNode->next = top;
            top = newNode;
            cout<<"Data Pushed on to the stack\n";
        }

        int pop(){
            if (top == nullptr)
            {
                cout<<"UnderFlow\n";
                return -1;
            }
            node* temp = top;
            int data = temp->data;
            top = temp->next;
            return data;
        }

         int peek(){
            if (top == nullptr)
            {
                cout<<"UnderFlow\n";
                return -1;
            }
            return top->data;
        }
};
int main(){
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.peek();
    // cout<<st.pop()<<endl;
    // cout<<st.pop()<<endl;
    return 0;
}