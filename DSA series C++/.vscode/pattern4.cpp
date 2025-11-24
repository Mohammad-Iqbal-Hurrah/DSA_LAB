/*print the following pattern
*
**
***
****
*****
*/
#include<iostream>
using namespace std;
int main(){
    int rows = 5;
    int cols = rows;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <i+1; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
    return 0;
}