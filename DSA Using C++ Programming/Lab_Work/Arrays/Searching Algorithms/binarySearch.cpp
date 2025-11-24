#include<iostream>
using namespace std;
int binSearch(int arr[],int size, int data){
    int low = 0;
    int high = size-1;
    while(low<=high){
        int mid = (low+high)/2;
        if (arr[mid]== data)
        {
            return mid;
        }else if (arr[mid]>data)
        {
            high = mid-1;   
        }else
        low = mid+1;
    }
    return -1; // means element not found in the array
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    cout<<"Element found at index "<<binSearch(arr,7,5);
    return 0;
}