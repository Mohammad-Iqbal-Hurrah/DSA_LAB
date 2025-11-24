/*Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2*/

#include<iostream>
#include<vector>
using namespace std;
 int majorityElement(vector<int>& vec) {
        int freq = 0;
        int ans = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (freq == 0)
            {
                ans = vec[i];
            }
            if (ans == vec[i])
                freq += 1;
            else
                freq -= 1; 
            if (freq>(vec.size()/2))
            {
                return ans;
            }
            
        }
        return ans; 
    }
int main(){
    vector<int> vec = {2,2,1,1,1,2,2};
    cout<<majorityElement(vec);
    return 0;
}
