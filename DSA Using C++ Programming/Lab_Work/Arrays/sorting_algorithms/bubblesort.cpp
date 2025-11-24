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
int bubbleSort(int *arr,int n){     //BUBBLE SORT ALGORITHM
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
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
    arr[n] = bubbleSort(arr,n);
    cout<<"\n\nArray After Sorting.\n\n\n";
    display(arr,n);
    return 0;
}