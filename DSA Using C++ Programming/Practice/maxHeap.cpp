#include <iostream>
using namespace std;
int* maxHeap(int arr[], int size)
{
    int *newArr = new int[size];
    newArr[0] = arr[0];
    for (int i = 1; i < size; i++)
    {
        newArr[i] = arr[i];
        int j = i;
        while (j > 0)
        {   //[1,2,5,3,8]
            int parent = (j - 1) / 2;
            if (newArr[j] > newArr[parent])
            {
                swap(newArr[j], newArr[parent]);
            }
            j = parent;
        }
    }
    
    return newArr;
}
int main()
{
    int arr[] = {4,1,9,8,6,3};
    int size = 6;
    int* newArr = maxHeap(arr,size);
    for (int i = 0; i < size; i++)
    {
        cout<<newArr[i]<<" ";
    }
    return 0;
}