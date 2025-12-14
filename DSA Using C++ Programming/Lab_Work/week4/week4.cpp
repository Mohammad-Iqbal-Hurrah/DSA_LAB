/*Topics: Quick Sort, Merge Sort, comparison of algorithms.
 Problems: Implement Quick Sort and Merge Sort. Compare execution times
with Bubble Sort for different input sizes. */
#include <iostream>
#include <ctime>
using namespace std;
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int division(int arr[], int low, int high)
{ //{12,3,2,45,7,4,0,2}
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]); //{0,3,2,45,4,12,2}
        }
    }
    swap(arr[i + 1], arr[high]); //{0,2,2,45,4,12,3}
    return i + 1;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = division(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void bubbleSort(int *arr, int n)
{ // BUBBLE SORT ALGORITHM
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void getRandArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}

void copyArr(int src[], int dst[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dst[i] = src[i];
    }
}
int main()
{
    srand(time(0));
    int sizes[] = {1000, 10000, 100000};
    for (int i = 0; i < 3; i++)
    {
        int n = sizes[i];
        cout << "Array of size: " << n << "\n";
        int *original = new int[n];
        getRandArr(original, n);
        int *arr = new int[n];
        copyArr(original, arr, n);
        int low = 0, high = n - 1;
        double start = clock();
        mergeSort(arr, low, high);
        double end = clock();
        cout << "Time taken by merge sort " << (end - start) * 1000 / CLOCKS_PER_SEC << " ms \n";

        copyArr(original, arr, n);
        start = clock();
        quickSort(arr, low, high);
        end = clock();
        cout << "Time taken by quick sort " << (end - start) * 1000 / CLOCKS_PER_SEC << " ms \n";

        copyArr(original, arr, n);
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        cout << "Time taken by bubble " << (end - start) * 1000 / 
        CLOCKS_PER_SEC << " ms \n";
    
delete[] original;
delete[] arr;
    }
    return 0;
}