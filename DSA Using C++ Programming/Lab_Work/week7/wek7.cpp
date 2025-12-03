#include <iostream>
#include <string>
using namespace std;
class patient
{
public:
    string name;    //patient name 
    int priority;   //order of severity/ priority
};
class maxHeap
{
public:
    patient *arr;   //patient array
    int size;       //total number of patients in the array
    int capacity;   //maximum number of patients the array can store
};

maxHeap *createMaxHeap(int capacity)    //creates a heap object in memory
{
    maxHeap *heap = new maxHeap;    //object creation
    heap->size = 0;     //initializing size of the patient array to zero
    heap->capacity = capacity;      //initializing capacity of the patient array
    heap->arr = new patient[capacity];  //allocating memory for the patient array
    return heap;    //returns heap object of class maxHeap
}

void heapifyUp(maxHeap* heap, int index)    //places higher priority patients at the top (root node) emergency
{
    while (index != 0)  //jab tak index 0 k barabar nahe hoga tab tak children node agr badey hongey parent se tab tak swap honge matlab badey priority waley root pe aayengey
    {
        int parent = (index - 1) / 2;   //jo b element aayega (heap) auska parent dhond k deta hai 
        if (heap->arr[index].priority > heap->arr[parent].priority) //comparing 
        {
            swap(heap->arr[index], heap->arr[parent]);  //swapping
        }
        else    //agr parent already bada hai too bas loop break hoga swap nahe hoga 
        {
            break;
        }
    }
}
void insert(maxHeap *heap, const string &name, int priority)    //inserts a new patient according to the severity/priority of that patient
{
    if (heap->size == heap->capacity)   //check if size and capacity are equal--> means the heap is already full(all beds occupied)
    {
        cout<< "The heap is full\n";
        return;                 //go back from where the function was called
    }
    patient newPatient;     //if the heap is not full then new patient is created 
    newPatient.name = name;         // EQUALS heap->arr[heap->size].name = name;    (assigning name)
    newPatient.priority = priority; // EQUALS heap->arr[heap->size].priority = priority;    (Assigning priority)
    heap->arr[heap->size] = newPatient;     //adding new patient in the array at index(size) which is 0 if the heap is empty
    heapifyUp(heap, heap->size);    //if there are already some patients and a new patient comes with higher severity/priority-->heafyUp places it at the top of the heap
    heap->size++;   //updating size after every new patient 
    cout << newPatient.name<<" pushed on to the priority queue\n";  //it is just a message for confermation
}

void heapifyDown(maxHeap *heap, int index)  //jab element remove hoga too pehle root node remove hojayega too phr root node pe sabse last wala leaf aayega ausko correct jagah pe place karne k liye hamey left child aur right child compare karne jo bada hoga root node pe wahi wala child khada hoga aur ye tab tak chalega jab tak sarey child nodes k parent greater na hojaye q ki ye recursively call hota rahega
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
        heapifyDown(heap,largest);  //recursion
    }
}

patient extractMax(maxHeap* heap){  //ye hamey max severity/ priority wala patient deta hai aur size ko decrease karta hai by 1
    if (heap->size == 0)
    {
        cout<<"Heap is empty.\n";
        patient empty = {"", -1};   //patient ka naam kuch nahe hai aur priority -1 means koye patient hai he nahe q ki priority 1 se start hoti hai 
        return empty;
    }
    patient max = heap->arr[0];    //saving root node max priority wala patient 
    heap->arr[0] = heap->arr[heap->size - 1]; //root node pe ab last wala leaf node aaraha hai
    heap->size--;   // size update hogaya 
    heapifyDown(heap, 0);   //ye ab phr se maxheap bana k dega auper 
    return max;     //zyada priority wala patient bej do wahaan jahaan se call kee hai function ko 
}

void printHeap(maxHeap *heap)   //heap ko print karne k liye 
{
    cout << endl;   //new line character 
    for (int i = 0; i < heap->size; i++)
    {
        cout << "Name: " << heap->arr[i].name << " And Priority: " << heap->arr[i].priority << endl;    //prints patient name and priority
    }
}
int main()
{
    maxHeap* heap = createMaxHeap(10);  //aek pointer banaya heap jiske pass asli heap ka address hai aur auspe kaam karta hai
    insert(heap, "Patient A", 4);   //Patient A with severity 4
    insert(heap, "Patient B", 5);   //Patient B with severity 5
    insert(heap, "Patient C", 2);
    insert(heap, "Patient D", 3);
    insert(heap, "Patient E", 1);
    cout<<"Heap after insertion.";
    printHeap(heap);    //print heap 

    printf("Treating patients in order of severity:\n"); 
    while (heap->size > 0) { 
        patient p = extractMax(heap);   //highest priority wala patient p mai save hojayega aur pehle ausko he treat kiya jayega  
        cout<<"Name: "<<p.name<<", Priority/Severity: "<<p.priority<<endl;
    } 
 
    delete[] heap->arr;   //patient array deallocate hogaye 
    delete[] heap;        //clear heap memory
    return 0;
}