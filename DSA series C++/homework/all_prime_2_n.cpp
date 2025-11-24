// Write a function to print all prime numbers from 2 to n
#include<iostream>
using namespace std;
void primes(int n){
    bool isPrime = true; 
    for (int i = 2; i <= n; i++)
    {
        isPrime = true;
        for (int j = 2; j <=(i/2); j++)
        {
            if (i%j==0)
            {
                isPrime=false;
                break;  //stop inner loop for number i (e.g.,15->3*5=STOP)
            }
            
        }
        if (isPrime==1)
        {
            cout<<i<<" ";
        }
        
                  
    }
}
int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    cout<<"Prime numbers from 2 to "<<n<<" are as: ";
    primes(n);
    return 0;
}