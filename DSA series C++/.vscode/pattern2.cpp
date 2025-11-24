/* print this pattern.
    ABCD
    ABCD 
    ABCD
    ABCD*/
#include <iostream>
using namespace std;
int main()
{
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;
    for (int i = 0; i < r; i++)    //outer loop
    {
        char ch = 'A';
        for (int j = 0; j < c; j++)    //inner loop
        {
            cout << ch;  
            ch++;
        }
        cout << endl;
    }

    return 0;
}