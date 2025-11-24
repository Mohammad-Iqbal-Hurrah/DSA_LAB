#include<iostream>
#include<vector>
using namespace std;
void sortColor(vector<int> & nums){
    int mid = 0;
    int low = 0;
    int high = nums.size()-1;
    while(mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid],nums[low]);
            mid +=1;
            low +=1;
        }else if (nums[mid] == 2)
        {
            swap(nums[mid],nums[high]);
            high -= 1;
        }else
        mid += 1;
        
    }
}
int main(){
    vector<int> vec = {2,0,2,1,1,0};
    sortColor(vec);
    for (int val: vec)
    {
        cout<<val<<" ";
    }
    
    return 0;
}