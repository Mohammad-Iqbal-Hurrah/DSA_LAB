#include<iostream>
using namespace std;
#include<vector>
 vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0;i<nums.size();i++)
        {
            for (int j = i+1; j<nums.size();j++)
            {
                if (nums[i]+nums[j] == target)
                {
                    return {i,j};
                }
                
            }
            
        }
        return {};
    }
int main(){
    vector<int> vec= {11,15,2,7};
    int target = 9;
    vec = twoSum(vec,target);
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    
    return 0;
}