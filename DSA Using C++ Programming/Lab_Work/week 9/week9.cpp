#include <iostream>
using namespace std;
class item
{
public:
    int value;
    int weight;
    double ratio;
    item(int val, int w)
    {
        value = val;
        weight = w;
        ratio = val / w;
    }
};

int compareItems(const void *a, const void *b)
{
    item *item1 = (item *)a;
    item *item2 = (item *)b;
    if (item1->ratio < item2->ratio) // means place items in decending order-->smallest at the end of the array
        return 1;
    if (item1->ratio > item2->ratio)
        return -1;
    return 0;
    // return (item1->ratio<item2->ratio - item1->ratio>item2->ratio) simple hai but samajna thoda complex hai
}

double fractionalKnapsack(int capacity, item arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i].ratio = (double)arr[i].value / arr[i].weight;
    }
    qsort(arr, size, sizeof(item), compareItems);
    double totalValue = 0.0;
    int remainingCapacity = capacity;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].weight <= capacity)
        {
            totalValue += arr[i].value;
            remainingCapacity -= arr[i].weight;
        }
        else if (remainingCapacity > 0)
        {
            double fraction = (double)remainingCapacity / arr[i].weight;
            totalValue += arr[i].value * fraction;
            remainingCapacity = 0;
        }
    }

    return totalValue;
}
int main()
{
    int capacity = 50;
    item items[] = {
        item(60, 10),
        item(100, 20),
        item(120, 30)
    };
    int size = sizeof(items) / sizeof(items[0]);

     double maxValue = fractionalKnapsack(capacity, items, size); 
    printf("Maximum value: %.2f\n", maxValue);
}