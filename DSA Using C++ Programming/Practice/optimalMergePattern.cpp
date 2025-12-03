#include <iostream>
using namespace std;
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int optimalMergePattern(int arr[], int size)
{
    bubbleSort(arr, size); // sort the array so that the small elements comes at earlier indices
    int cost = 0;
    while (size > 1)
    {
        int mergedValue = arr[0] + arr[1]; // merge 2 small values
        cost += mergedValue;               // add in the cost
        arr[0] = mergedValue;              // place the result at index 0
        for (int i = 1; i < size; i++)
        {
            arr[i] = arr[i + 1]; // shift the array elements
        }
        size--;                // reduce the size by 1
        bubbleSort(arr, size); // sort the array again if a larger element comes at index 0
        // optimalMergePattern(arr,size);   //wrong answer
    }
    return cost;
}
int main()
{
    int arr[] = {1, 2, 4, 5}; // min cost = 22
    int size = 4;
    int result = optimalMergePattern(arr, size); // store cost in result varible
    cout << result;                              // result must b equal to 22.
    return 0;
}