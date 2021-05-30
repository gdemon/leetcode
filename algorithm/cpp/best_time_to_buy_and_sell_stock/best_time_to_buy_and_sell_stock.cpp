// Source : 
// Author : Edgar Wu
// Date   : 30/05/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

 

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104


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

We need to find out the minimal value during the process, and find out the the maximal profit.

At the beginning, min_idx points to the index 0.
Then we traversal the afterward sequence to get profit by prices[i] - prices[min_idx].
This implies we sell buy stock on min_idx and sell on day i.
And track maximal profit once the profit get bigger

If the profit is negative (<0), it implies i points to a value smaller than the value pointed by min_idx.
So we move the min_idx to i (rebase to i) because now it is the minimal value.

Then we iterate the process the calculate maximal profit continously.

Some people think find the highest-price & lowest-price, it may not work.
It's a uni-direction sequence problem. 
If the highest-price appears ahead of lowest-price, it's invalid transaction.

If you want to do so, find the minimal value first and find out maximal value after the day.

 */


class Solution {
public:

    int maxProfit(vector<int> &prices) {
        
        int max_profit=0, min_idx=0, profit=0;
        
        for (int i=1; i<prices.size(); i++) {
                       
            profit = prices[i] - prices[min_idx];
            
            if (profit < 0)
                min_idx = i;

            
            if (profit > max_profit )
                max_profit = profit;
            
        }
        
        return max_profit;
        
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
