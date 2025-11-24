/*Dynamic array and it's operations
1. push
2. pop
3. access random index.*/
#include <iostream>
using namespace std;
class dynamicArray
{
private:
    int *arr;
    int size;
    int capacity;

public:
    dynamicArray()
    { // constructor to initialize size, capacity and dynamically allocate memory to thr array
        capacity = 2;
        arr = new int[capacity];
        size = 0;
    }
    void display()
    { // member function/method to display all the elements in the array
        cout << "Inside Show array method.\n";
        if (size < 0)
        {
            cout << "The array is empty.\n";
        }

        cout << "Array elements are:\n";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void resize()
    { // member funtion for resizing the array
        cout << "inside resize method.\n";
        capacity *= 2;
    }
    void push(int index, int data)
    { // method to push an element in the array
        cout << "inside push method.\n";
        if (size == capacity)
        {
            resize();
            int *newArr = new int[capacity]; // dynamically allocate memory to new array
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i]; // copying elements of old array into new array
            }
            arr = newArr; // pointing old array pointer towards new array
        }
        for (int i = size; i > index; i--)
        {
            arr[i] = arr[i - 1]; // shiftinf elements
        }
        cout << "size = " << size << endl;
        arr[index] = data;
        size += 1; // increasing the size of the array by 1
    }
    int pop()
    {
        int index;
        cout << "\ninside pop method.\n";
        cout << "\nEnter the index.\n";
        cin >> index;
        int element;
        if ((index < 0) || (index > size - 1))
        {
            cout << "Wrong Index.";
        }
        else
        {
            element = arr[index];
            for (int i = index; i < size; i++)
            {
                arr[i] = arr[i + 1];
            }
            size -= 1;
            return element;
        }
    }
    int randInd(int index)  // method to access any random index and show the data on that index.
    { 
        cout << "Inside access randon index method.\n";
        if (index > size - 1)
        {
            cout << "Cannot access wrong indices greater than the size of the array.\n";
            return 0;
        }
        else
        {
            return arr[index];
        }
    }
};
int main()
{
    dynamicArray d;     //creating an object and calling constructor
    d.push(0, 20);      //calling push function and pushing 20 at 0 index
    d.push(1, 70);      //calling push function again and pushing 70 at 1 index
    d.display();        //calling display function and printing all the elements of an array
    cout << "element = " << d.randInd(6) << endl;   //accessing any specific index to see which element is stored at that index
    cout << d.pop();    //calling pop method to remove and print the last element at a specific index
    d.display();    //displaying all the elements of the array to check if the element is removed or not
    return 0;
}