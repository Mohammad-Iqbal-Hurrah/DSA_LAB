#include<iostream>
using namespace std;
int main(){
    int n;
    bool isPrime=true;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    for (int i = 2; i*i <=n; i++)
    {
        if (n%i==0)
        {
            isPrime = false;
            break;
        }
    }
    if(isPrime==1){
        cout<<"The number is prime."<<endl;
    }else{
        cout<<"The number is not prime."<<endl;
    }
    
    return 0; 
}