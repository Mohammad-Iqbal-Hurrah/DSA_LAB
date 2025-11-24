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
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int selectionSort(int *arr,int n){     //SELECTION SORT ALGORITHM
    for (int i = 0; i < n-1; i++)   //n-1 --> because last element will get its correct position automatically.
    {
        int min_ind = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[min_ind])
            {
                min_ind = j;
            }
            
        }
        if (min_ind != i)
        {
            swap(arr[min_ind],arr[i]);  //SWAP function call
        }
        
        
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
    arr[n] = selectionSort(arr,n);
    cout<<"\n\nArray After Sorting.\n\n\n";
    display(arr,n);
    return 0;
}