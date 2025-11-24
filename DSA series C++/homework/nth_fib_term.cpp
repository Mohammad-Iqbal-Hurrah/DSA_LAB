//Write a function to print nth fibonacci term.
#include<iostream>
using namespace std;
int fibonacci(int n){
    if (n==1)
    {
        return 1;
    }else if (n == 0)
    {
        return 0;
    }else{
    int a =0,b=1;
    int next;
    for (int i = 3; i <= n; i++)
    {
        next = a+b;
        int temp = b;
        b=a;
        a=next;
    }
}
}
int main(){
    int n;
    cout<<"Enter the nth term you want to print in the fibonacci series: ";
    cin>>n;
    int res =fibonacci(n);
    cout<<res;
    return 0;
}