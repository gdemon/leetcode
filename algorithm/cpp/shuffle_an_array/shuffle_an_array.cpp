// Source : 
// Author : Edgar Wu
// Date   : 04/07/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given an integer array nums, design an algorithm to randomly shuffle the array.

Implement the Solution class:

    Solution(int[] nums) Initializes the object with the integer array nums.
    int[] reset() Resets the array to its original configuration and returns it.
    int[] shuffle() Returns a random shuffling of the array.

 

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must be equally likely to be returned. Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

 

Constraints:

    1 <= nums.length <= 200
    -106 <= nums[i] <= 106
    All the elements of nums are unique.
    At most 5 * 104 calls will be made to reset and shuffle.




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
    // initiaize the private data member when construct instance
    Solution(vector<int>& nums) : _nums(nums), _solution(nums) {
        // initialize random seed with current time
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        //Fisher Yates
        //https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
        
        int i = _solution.size();
        
        while ( --i > 0 ) {
            int j = rand() % (i+1);
            swap(_solution[i], _solution[j]);
        }
        return _solution;
        
    }
private:
    vector<int> _nums, _solution;

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
