// Source : 
// Author : Edgar Wu
// Date   : 01/11/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 

Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

    Try to come up as many solutions as you can, there are at least 3 different ways
    to solve this problem.
    Could you do it in-place with O(1) extra space?

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

 

Constraints:

    1 <= nums.length <= 2 * 104
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105


 



*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
    }
};







void verify_func(Solution &sln, string &haystack, string &needle) {
	int found = sln.strStr(haystack, needle);

	if (found != -1) {
		cout << "found " << needle << " in " << haystack << " on " << found << endl;
	} else {
		cout << "can't found " << needle << " in " << haystack << endl;
	}
}

int main()
{
    Solution sln;
	string haystack, needle;

	haystack = "mississippi";
    needle = "issi";
	verify_func(sln, haystack, needle);

	needle = "issip";
	verify_func(sln, haystack, needle);
		
	haystack = "babbbbbabb";
    needle = "bbab";
	verify_func (sln, haystack, needle);

    return 0;
}
