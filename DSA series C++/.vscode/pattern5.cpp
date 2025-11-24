/*print the following pattern 
1 num++               A (Ch++)
2 2                   B B
3 3 3                 C C C 
4 4 4 4               D D D D
5 5 5 5 5             E E E E E 
*/
#include<iostream>
using namespace std;
int main(){
    int lines = 5;
    char ch = 'A';
    for (int i = 0; i < lines ; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout<<ch<<" ";
            
        }
        ch++;
        cout<<endl;
    }
    
    return 0;
}