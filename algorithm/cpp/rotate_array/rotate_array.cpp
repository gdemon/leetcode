<<<<<<< HEAD
// Source : 
// Author : Edgar Wu
// Date   : 01/25/2020
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <vector>
using namespace std;

#define INT_MIN     (-INT_MAX - 1)
#define INT_MAX      0x7FFFFFFF

void print_ary(vector<int> &tst);


class Solution {
public:
	void revert(int start, int end, vector<int>& nums) {
		unsigned long sz = end - start + 1;		// count extra one to calculate exact size
		int i, tmp;
		for (i=0; i < sz/2; i++) {
			tmp = nums[(start+i)];
			nums[(start+i)] = nums[(end-i)];
			nums[(end-i)] = tmp;
		}
	}
	void rotate(vector<int>& nums, int k) {
		unsigned long sz = nums.size();
		int last_k = k % sz;	// here comes the trap, consider the wrap arround case
		revert(0, sz-1, nums);
		revert(0, last_k-1, nums);
		revert(last_k, sz-1, nums);
	}
};




#define TEST(n, e)  printf("%12d  =>  %-12d    %s!\n",  n, sln.reverseString(n),  e == sln.reverseString(n)?"passed":"failed")

void print_ary(vector<int> &tst) {
	for (unsigned long i = 0; i < tst.size(); i++)
		cout << tst[i];
	cout << endl;
}
void test_rot_ary(vector<int> &tst, const int k, Solution sln) {
	print_ary(tst);
	sln.rotate(tst, k);
	print_ary(tst);
}

int main()
{
	Solution sln;
	vector<int> tst;
	for (int i = 0; i <7; i++ )
		tst.push_back(i+1);
	//test_rot_ary(tst, 3, sln);

	test_rot_ary(tst, 10, sln);
/*
	//basic cases
    TEST(  123,  321);
    TEST( -123, -321);
    TEST( -100,   -1);
    TEST( 1002, 2001);
    //big integer
    TEST( 1463847412,  2147483641);
    TEST(-2147447412, -2147447412);
    TEST( 2147447412,  2147447412);
    //overflow
    TEST( 1000000003, 0);
    TEST( 2147483647, 0);
    TEST(-2147483648, 0);
    //customized cases
    if (argc<2){
        return 0;
    }
    printf("\n");
    for (int i=1; i<argc; i++) {
        int n = atoi(argv[i]); 
        printf("%12d  =>  %-12d    %s!\n",  n, sln.reverseString(n), sln.reverseString(sln.reverseString(n))==n ? "passed":"failed");
    }
*/
    return 0;
}
=======
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
>>>>>>> 0729e444b16db7e9fe5cf56a5ef0d362f354e24f
