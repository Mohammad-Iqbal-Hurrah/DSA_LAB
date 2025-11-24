#include<iostream>
using namespace std;
int main(){
    int arr[]={12,7,5,23,1,5,4,0,2};
    cout<<"Array before sorting: \n";
    for (int i = 0; i < (sizeof(arr)/sizeof(int)-1); i++)
    {
        cout<<arr[i]<<" ";
    }
    for (int i = 0; i < (sizeof(arr)/sizeof(int)); i++)
    {
        int min_ind = i;
        for (int j = i+1; j < (sizeof(arr)/sizeof(int)); j++)
        {
            if (arr[j]<arr[min_ind])
            {
                min_ind = j;
            }
            
        }
        if (min_ind != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_ind];
            arr[min_ind] = temp;
        }
        
    }
    cout<<"\nArray after sorting: \n";
     for (int i = 0; i < (sizeof(arr)/sizeof(int)); i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}