#include<iostream>
using namespace std;
int main(){
    int arr[] = {23,4,23,2,0,34,5,23,1};
    int size = (sizeof(arr)/sizeof(int));
    int smallest = INT32_MAX;   //assume it is largest among all the array lements
    for (int i = 0; i < size; i++)
    {
        if (arr[i]<smallest)
        {
            smallest = arr[i];
        }
        
    }
    cout<<"Smallest = "<<smallest;
    
    return 0;
}