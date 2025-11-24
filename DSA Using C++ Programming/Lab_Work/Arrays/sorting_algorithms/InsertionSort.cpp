#include<iostream>
using namespace std;
int insert(int *arr,int n){
    for (int i = 0; i <n; i++)
    {
        cout<<"Enter "<<i+1<<"th element: ";
        cin>>arr[i];
    }
    return arr[n];
}
void display(int *arr,int n){
    cout<<"Array elements are: \n";
    for (int i = 0; i < n; i++)
    {
        cout<<"element at "<<i<<" index = "<<arr[i]<<" "<<endl;
    }
    
}
int insertionSort(int *arr,int n){     //INSERTION SORT ALGORITHM
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j >=0 && arr[j]>key) //[23,12,5,2]
        {
            arr[j+1]= arr[j];
            j -=1;
        }
    arr[j+1] = key;  
        
    }
    
    return arr[n];
}
int main (){
    int n ;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of the array: \n";
    arr[n] = insert(arr,n);
    cout<<"\n\nArray Before Sorting.\n\n\n";
    display(arr,n);
    arr[n] = insertionSort(arr,n);
    cout<<"\n\nArray After Sorting.\n\n\n";
    display(arr,n);
    return 0;
}