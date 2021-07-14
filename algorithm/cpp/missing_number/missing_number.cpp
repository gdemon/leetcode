// Source : 
// Author : Edgar Wu
// Date   : 15/07/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given an array nums containing n distinct numbers in the range [0, n], return the 
only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity 
and O(n) runtime complexity?

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 
2 is the missing number in the range since it does not appear in nums.

Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 
8 is the missing number in the range since it does not appear in nums.

Example 4:

Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 
1 is the missing number in the range since it does not appear in nums.

 

Constraints:

    n == nums.length
    1 <= n <= 104
    0 <= nums[i] <= n
    All the numbers of nums are unique.



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
    int missingNumber(vector<int>& nums) {
        // the value will be distributed from 0 ~ n, but one of it will missing
        // so we exlusive or all the value of nums with integer from 1 ~ n (actually, 0~n, but xor 0 is useless).
        // then the remain value is the missing one.
        // why? because 1 xor 1 == 0, 2 xor 2 == 0, every pair will xor itself except the missing one.
        // missing one xor 0 == missing one
        int i, res = 0;

        for (i = 0; i < nums.size(); i++)
            res ^= nums[i];
        // xor integer from 1~n, no need to xor zero.....
        // Take care the loop condtion, because integer ranges from 0 ~ n, the condtion should be <= n
        for (i = 1; i <= nums.size(); i++)
            res ^= i;

        return res;
    }
};















