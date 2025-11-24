/*Topic: Setting up programming environment (Python/C),writing simple programms, basic input/output, variables etc...
Problem: Write a program to perform arithmetic operations, take user input, and display output.*/
#include<iostream>
using namespace std;
int main(){
    int a,b;    //Two variables declared here
    char ch;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    cout<<"Press + for addition of "<<a<<" + "<<b<<".\n";
    cout<<"Press - for subtraction of "<<a<<" - "<<b<<".\n";
    cout<<"Press * for multiplication of "<<a<<" * "<<b<<".\n";
    cout<<"Press / for division of "<<a<<" / "<<b<<".\n";
    cout<<"Press % for modulus of "<<a<<" % "<<b<<".\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch){
        case '+':
            cout<<"The sum of "<<a<<" and "<<b<<" is "<<a+b;
            break;
        case '-':
            cout<<"The subtraction of "<<a<<" and "<<b<<" is "<<a-b;
            break;
        case '*':
            cout<<"The multiplication of "<<a<<" and "<<b<<" is "<<a*b;
            break;
        case '/':
            cout<<"The divsion of "<<a<<" and "<<b<<" is "<<a/b;
            break;
        case '%':
            cout<<"The modulus of "<<a<<" and "<<b<<" is "<<a%b;
            break;
        default:
            cout<<"Invalid Input.\n";
    }
    return 0;
}

//Week one Complete. Date 15-10-2025