// Source : 
// Author : Edgar Wu
// Date   : 04/07/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
You are a professional robber planning to rob houses along a street. Each house has
a certain amount of money stashed, the only constraint stopping you from robbing 
each of them is that adjacent houses have security systems connected and it will 
automatically contact the police if two adjacent houses were broken into on the 
same night.

Given an integer array nums representing the amount of money of each house, return 
the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 400



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

/*
 * Dynamic Programming
 *
 * We can easy find the recurive fomular:
 *
 *     dp[n] = max( 
 *                    dp[n-1],   // the previous house has been robbed. 
 *                    dp[n-2] + money[n]  // the previous house has NOT been robbed.
 *                )
 *                  
 * The initalization is obvious:
 *     dp[1] = money[1]
 *     dp[2] = max(money[1], money[2])
 *
 */


class Solution {
public:
    int rob(vector<int>& nums) {
        int ary_size = nums.size();
        if (0 == ary_size) 
            return 0;

        vector<int> max_loot(ary_size, 0);
        if (ary_size >= 1) 
            max_loot[0] = nums[0];
        if (ary_size >= 2) 
            max_loot[1] = max(nums[0], nums[1]);

        for (int i=2; i<ary_size; i++)
            max_loot[i] = max(max_loot[i-1], max_loot[i-2] + nums[i]);

        return max_loot[ary_size-1];
    }
};

/*
 * Acutally, we no need to allocate an additional array for DP.
 * we can only use several variables to record previous steps
 */

int rob2(vector<int> &money) {
    int n2=0; // dp[i-2];
    int n1=0; // dp[i-1];

    for (int i=0; i<money.size(); i++){
        int current = max(n1, n2 + money[i]);
        n2 = n1;
        n1 = current;
    }
    return n1;
}




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
