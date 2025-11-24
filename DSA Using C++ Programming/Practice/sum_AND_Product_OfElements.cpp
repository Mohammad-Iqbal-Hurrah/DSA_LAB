#include<iostream>
using namespace std;
int main(){
    int arr[] = {23,4,23,2,34,5,23,1};
    int size = (sizeof(arr)/sizeof(int));
    int sum = 0;
    int product = 1;
    for (int i = 0; i < size; i++)
    {
        sum +=arr[i];
        product *=arr[i];
    }
    cout<<"Sum = "<<sum<<"\n";
    cout<<"Product = "<<product<<"\n";
    
    return 0;
}