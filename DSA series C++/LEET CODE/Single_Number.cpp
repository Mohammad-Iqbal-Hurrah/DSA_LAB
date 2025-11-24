#include<iostream>
#include<vector>
using namespace std;
int single(vector<int>& arr){
    int ans = 0;
    for (int val: arr)
    {
        ans ^= val;
    }
    return ans;
}
int main(){
    vector<int> vec = {1,1,2,2,3,3,5,6,6};
    cout<<single(vec);
    
    return 0;
}
