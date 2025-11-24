// Nested Loop-->loop inside loop
#include <iostream>
using namespace std;
int main()
{
    int r,c;
    cout<<"Enter number of rows: ";
    cin>>r;
    cout<<"Enter number of columns: ";
    cin>>c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "*";        //box shape (square or rectangle)
        }
        cout << endl;
    }

    return 0;
}