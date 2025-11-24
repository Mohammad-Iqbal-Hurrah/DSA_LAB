#include <iostream>
using namespace std;
int division(int arr[], int low, int high)
{   //{12,3,2,45,7,4,0,2}
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}
void quickSort(int arr[],int low, int high){
    if (low < high) {
        int p = division(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}
void display(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
int main()
{
    int arr[] = {12,3,2,45,7,4,0,2};
    int size = sizeof(arr)/sizeof(int);
    cout<<"Before quick sort\n";
    display(arr,size);
    int low = 0;
    int high = size-1;
    quickSort(arr,low,high);
    cout<<"After quick sort\n";
    display(arr,size);
    return 0;
}