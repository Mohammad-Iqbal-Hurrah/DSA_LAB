/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];    //let the prefix be the first string of the array
        for (int i = 0; i < strs.size(); i++)
        {
            int j = 0;
            while (strs[i][j] == prefix[j] && j<prefix.size() && j<strs[i].size())  // Check characters or each string, variable j must be less than the size of the strings
            {
                j++;
            }
            prefix = prefix.substr(0,j);    //update the prefix to the matched characters only
            if (prefix.empty()) //if the prefix of the strings is not matched, then we can return empty string here
            {
                return " No Common Prefix";
            }
            
        }
        return prefix;
    }
int main(){
    vector<string> str = {"flower","dsfflow","dflight"};
    cout<<longestCommonPrefix(str);
    return 0;
}