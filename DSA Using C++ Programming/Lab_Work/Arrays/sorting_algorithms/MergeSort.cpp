#include<iostream>
using namespace std;
void mergeSort(int arr[], int low, int high){
    int mid = low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
}
int main(){
    int arr[] = {1,54,2,7,4,9,3};
    int low = 0;
    int high = 7;
    mergeSort(arr, low, high);
    return 0;
}