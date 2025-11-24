/*print the square pattern 
1 2 3
4 5 6
7 8 9 */
#include<iostream>
using namespace std;
int main(){
    int lines = 3;
    char ch = 'A';
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < lines; j++)
        {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
    
    return 0;
}