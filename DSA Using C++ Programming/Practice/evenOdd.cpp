#include<iostream>
using namespace std;
int main(){
    int n; 
    cout<<"Enter any number: "<<endl;
    cin>>n;
    if (n == 0)
    {
        cout<<"The number is zero "<<endl;
    }else if (n%2 != 0)
    {
        
        cout<<"The number is odd"<<endl;
    }
    else
    cout<<"Even number "<<endl;
    
    return 0;
}