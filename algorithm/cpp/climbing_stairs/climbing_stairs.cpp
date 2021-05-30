// Source : 
// Author : Edgar Wu
// Date   : 30/05/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step




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

/**
n = 1, only 1 ways, 1*1
n = 2, only 2 ways, 1*2, 2*1
n = 3, only 3 ways, but it can be look like this
n = 3, == (n=1) + 2*1 = 1*1 + 2*1
n = 3, == (n=2) + 1*1 = 1*3, 2*1 + 1*1
n = 3, == (n=1) + (n=2) = 1 + 2 = 3
n = 4 => iterate == (n=2) + (n=3)
 */

class Solution {
public:
    int climbStairs(int n) {
        // special cases
        if (n<=3) 
            return n;

        int i, new_ways;
        int ways[2]={2,3};
        for(int i=4; i<=n; i++) {
           int new_ways = ways[0] + ways[1];
           ways[0] = ways[1];
           ways[1] = new_ways;
        }
        return ways[1];
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
