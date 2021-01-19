// Source : 
// Author : Edgar Wu
// Date   : 01/11/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 

You are given an n x n 2D matrix representing an image, rotate the image by 90 
degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D 
matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Example 3:

Input: matrix = [[1]]
Output: [[1]]

Example 4:

Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]

 

Constraints:

    matrix.length == n
    matrix[i].length == n
    1 <= n <= 20
    -1000 <= matrix[i][j] <= 1000


 



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
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        if (sz == 1)
            return;
        if ((sz%2 == 0) && k == sz/2) {
            rotate_by_k_half_size(nums, k);
        } else {
            rotate_by_k(nums, k);
        }
        
        //for (int i=0; i < k; i++)            rotate_by_1(nums, k);
    }
    
    void rotate_by_1(vector<int>& nums, int k) {
        int tmp, j, ary_end;
        ary_end = nums.size()-1;
        tmp = nums[ary_end];
        //shift by 1
        for (int i=ary_end; i > 0; i--)
            nums[i]=nums[(i-1)];
        
        nums[0]=tmp;
    }
    
    void rotate_by_k(vector<int>& nums, int k) {
        int t1, t2, j, sz, beg_idx, new_idx;
        sz = nums.size();
        t1 = nums[0];
        beg_idx = 0;
        
        for (int i=0; i < sz; i++) {
            new_idx = (beg_idx + k)%sz;
            t2 = t1;
            t1 = nums[new_idx];
            nums[new_idx]= t2;
            beg_idx = new_idx;
        }
    }
    
    // this special case will cause taht swap half elements
    void rotate_by_k_half_size(vector<int>& nums, int k) {
        int sz = nums.size();
        int tmp, new_idx;
        for (int i=0; i < sz/2; i++) {
            new_idx = (i+k) % sz;
            tmp = nums[new_idx];
            nums[new_idx] = nums[i];
            nums[i] = tmp;
        }
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
