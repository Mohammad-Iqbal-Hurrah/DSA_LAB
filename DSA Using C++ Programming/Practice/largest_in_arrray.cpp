#include<iostream>
using namespace std;
int main(){
    int arr[] = {23,4,23,2,50,34,5,23,1};
    int size = (sizeof(arr)/sizeof(int));
    int largest = INT32_MIN;   //assume it is smallest among all the array lements
    for (int i = 0; i < size; i++)
    {
        if (arr[i]>largest)
        {
            largest = arr[i];
        }
        
    }
    cout<<"largest = "<<largest;
    
    return 0;
}