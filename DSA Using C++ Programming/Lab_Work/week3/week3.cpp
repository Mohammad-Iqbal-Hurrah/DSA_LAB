/*Implement bubble sort. Generate arrays of different sizes(100,1000,10000z) and measure execution time for sorted, unsorted and reverse sorted inputs.*/
#include <iostream>
#include <ctime>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        { // this condition is only for sorted case.
            break;
        }
    }
}
void getRandArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
}
void copyArr(int src[], int dst[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dst[i] = src[i];
    }
}
void reverseSorted(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}
int main()
{
    srand(time(0));
    int sizes[] = {100, 1000, 10000};
    for (int i = 0; i < 3; i++)
    {
        int n = sizes[i];
        cout << "Array of size: " << n << "\n";
        int *original = new int[n];
        getRandArr(original, n);
        int *arr = new int[n];
        copyArr(original, arr, n);
        double start = clock();
        bubbleSort(arr, n);
        double end = clock();
        cout << "Random array time " << (end - start) * 1000 / CLOCKS_PER_SEC << " ms \n";

        copyArr(original, arr, n);
        bubbleSort(arr, n);
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        cout << "Sorted array time " << (end - start) * 1000 / CLOCKS_PER_SEC << " ms \n";

        copyArr(original, arr, n);
        bubbleSort(arr, n);
        reverseSorted(arr, n);
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        cout << "Reverse sorted array time " << (end - start) * 1000 / CLOCKS_PER_SEC << " ms \n";

        delete[] original;
        delete[] arr;
    }
    return 0;
}