// Source : 
// Author : Edgar Wu
// Date   : 03/07/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:

Input: nums = [1]
Output: 1

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23

 

Constraints:

    1 <= nums.length <= 3 * 104
    -105 <= nums[i] <= 105

 
Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.





*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <vector>
#include <string>
#include <iostream>
#include <sstream>


using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        unsigned long ary_sz = nums.size();
        if (0 == ary_sz)
            return 0;
        if (1 == ary_sz)
            return nums[0];
        // sum_vec[i] stores the maximum value of contineous subary untill i
        vector<int> sum_vec(ary_sz);
        int max_sum;

        sum_vec[0] = nums[0];
        max_sum = nums[0];
        for (int i = 1; i < ary_sz; i++) {
            // sum_vec[i-1] stores the maximum value of contineous subary untill i-1
            // if sum_vec[i-1] is negative and nums[i] is positive, sum_vec[i] will be nums[i]
            // because resum summation from i will have have a larger sum
            // if sum_vec[i-1] is posive and nums[i] is positive, sum_vec[i] will be nums[i] + sum_vec[i-1]
            sum_vec[i] = max(nums[i], nums[i] + sum_vec[i-1]);
            max_sum = max(max_sum, sum_vec[i]);
        }
        return max_sum;
        
    }
};




void verify_func(Solution &sln, int& n, string &res) {
    string test_res = sln.countAndSay(n); 

    if (test_res == res) {
        cout << "countAndSay(" << n << ")'s result is correct: " << test_res << endl;
    } else {
        cout << "countAndSay(" << n << ")'s result is wrong" << endl;
    }

}


int main(int argc, char** argv)
{
    Solution sln;
    int n;
	string res;

    if (argc > 1) {
        n = atoi(argv[1]);
        cout << sln.countAndSay(n) << endl;
        return 0;
    }
    

    n = 1;
    res = "1";
	verify_func(sln, n, res);

    n = 2;
    res = "11";
	verify_func(sln, n, res);

    n = 3;
    res = "21";
	verify_func(sln, n, res);

    n = 4;
    res = "1211";
	verify_func(sln, n, res);
    
    return 0;

}
