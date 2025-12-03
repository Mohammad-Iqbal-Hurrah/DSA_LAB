#include <iostream>
#include <string>
using namespace std;
class patient
{
public:
    string name;
    int priority;
};
class maxHeap
{
public:
    patient *arr;
    int size;
    int capacity;
};

maxHeap *createMaxHeap(int capacity)
{
    maxHeap *heap = new maxHeap;
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = new patient[capacity];
    return heap;
}

void heapifyUp(maxHeap *heap, int index)
{
    while (index != 0)
    {
        int parent = (index - 1) / 2;
        if (heap->arr[index].priority > heap->arr[parent].priority)
        {
            swap(heap->arr[index], heap->arr[parent]);
        }
        else
        {
            break;
        }
    }
}
void insert(maxHeap *heap, const string &name, int priority)
{
    if (heap->size == heap->capacity)
    {
        cout << "The heap is full\n";
        return;
    }
    patient newPatient;
    newPatient.name = name;         // EQUALS heap->arr[heap->size].name = name;
    newPatient.priority = priority; // EQUALS heap->arr[heap->size].priority = priority;
    heap->arr[heap->size] = newPatient;
    heapifyUp(heap, heap->size);
    heap->size++;
    cout << newPatient.name<<" pushed on to the priority queue\n";
}

void heapifyDown(maxHeap *heap, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap->size && heap->arr[left].priority > heap->arr[largest].priority)
    {
        largest = left;
    }
    if (right < heap->size && heap->arr[right].priority > heap->arr[largest].priority)
    {
        largest = left;
    }
    if (largest != index)
    {
        swap(heap->arr[index], heap->arr[largest]);
        heapifyDown(heap,largest);
    }
}

patient extractMax(maxHeap* heap){
    if (heap->size == 0)
    {
        cout<<"Heap is empty.\n";
        patient empty = {"", -1};
        return empty;
    }
    patient max = heap->arr[0]; 
    heap->arr[0] = heap->arr[heap->size - 1]; 
    heap->size--; 
    heapifyDown(heap, 0); 
    return max; 
}

void printHeap(maxHeap *heap)
{
    cout << endl;
    for (int i = 0; i < heap->size; i++)
    {
        cout << "Name: " << heap->arr[i].name << " And Priority: " << heap->arr[i].priority << endl;
    }
}
int main()
{
    maxHeap *heap = createMaxHeap(10);
    insert(heap, "Patient A", 4);
    insert(heap, "Patient B", 5);
    insert(heap, "Patient C", 2);
    insert(heap, "Patient D", 3);
    insert(heap, "Patient E", 1);
    cout<<"Heap after insertion.";
    printHeap(heap);

    printf("Treating patients in order of severity:\n"); 
    while (heap->size > 0) { 
        patient p = extractMax(heap);  
        cout<<"Name: "<<p.name<<", Priority/Severity: "<<p.priority<<endl;
    } 
 
    free(heap->arr); 
    free(heap);
    return 0;
}