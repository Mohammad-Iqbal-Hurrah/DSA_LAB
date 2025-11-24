#include<iostream>
using namespace std; 
int linearSearch(int arr[],int size, int target){   //linear search algorithm
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)   //Compare each element of array with the target element
        {
            return i;   //if found return the index of that element
        }
        
    }
    return -1;  //if not found, return -1-->means element is not in the array
    
}  
int main(){
    int arr[] = {10,22,45,2,6};
    int element  = 45;
    int size = sizeof(arr)/sizeof(int);
    int index = linearSearch(arr,size,element);
    if (index>=0)
    {
        cout<<"\nElement found at index: "<<index<<endl;
    }else{
        cout<<"\nElement not foud in the array"<<endl;
    }
    
    return 0;
}