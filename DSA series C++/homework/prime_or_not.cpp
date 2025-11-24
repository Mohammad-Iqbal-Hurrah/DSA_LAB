// write a function to check weather a number is prime or ot 
#include<iostream>
using namespace std;
void prime_or_not(int n){
    bool isPrime = true;
    if (n==1)
    {
        cout<<"1 is coprime";
        exit;
    }else if (n == 0)
    {
        cout<<"0 is nothing";
        exit;
    }else{
    for (int i = 2; i < (n/2)  ; i++)
    {
        if (n%i==0)
        {
            isPrime = false;
            break;
        }
        
    }
    if (isPrime==1)
    {
        cout<<n<<" is prime.";
    }else{
        cout<<n<<" is not prime";
    }
}
    
}
int main(){
    int n;
    cout<<"Enter number to check weather it is prime  or not: ";
    cin>>n;
    prime_or_not(n);
    return 0;
}