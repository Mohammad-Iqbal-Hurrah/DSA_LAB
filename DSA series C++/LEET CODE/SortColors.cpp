/*PROBLEM NUMBER 75
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> sortColors(vector<int> &nums){
    for (int i = 1; i < nums.size(); i++)
    {
        int key = nums[i];
        int j = i-1;
        while(j>=0 && nums[j]>key){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
    
    return nums;
}
int main(){
    vector<int> vec = {2,0,2,1,1,0};
    sortColors(vec);
    for (int val: vec)
    {
        cout<<val<<" ";
    }
    
    return 0;
}