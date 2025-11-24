/* print this pattern.
    1234
    1234
    1234
    1234 */
#include <iostream>
using namespace std;
int main()
{
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;
    for (int i = 1; i <= r; i++)    //outer loop
    {
        for (int j = 1; j <= c; j++)    //inner loop
        {
            cout << j;  //this will print 1234...c*r times 
        }
        cout << endl;
    }

    return 0;
}