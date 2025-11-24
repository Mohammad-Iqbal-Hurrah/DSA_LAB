//Buble Sort Algorithm
#include<iostream>
using namespace std;
int main(){
    int arr[] = {12,7,5,23,1,5,4,0,2};
    cout<<"Array before sorting: \n";
    for (int i = 0; i < (sizeof(arr)/sizeof(int)); i++)
    {
        cout<<arr[i]<<" ";
    }
    for (int i = 0; i < (sizeof(arr)/sizeof(int)); i++)
    {
        for (int j = 0; j < (sizeof(arr)/sizeof(int)); j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
        
    }
    cout<<"\nArray after sorting: \n";
    for (int i = 0; i < (sizeof(arr)/sizeof(int)); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}