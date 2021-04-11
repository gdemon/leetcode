// Source : 
// Author : Edgar Wu
// Date   : 11/04/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:

Input: root = [1,null,2]
Output: 2

Example 3:

Input: root = []
Output: 0

Example 4:

Input: root = [0]
Output: 1

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
    int maxDepth(TreeNode* root) {
        if (NULL == root)
            return 0;
        
        // leaf node
        if (!root->left && !root->right)
            return 1;
        
        int left_max_depth=1, right_max_depth=1;
        if (root->left)
            left_max_depth += maxDepth(root->left);
        
        if (root->right)
            right_max_depth += maxDepth(root->right);
                    
        return left_max_depth>right_max_depth?left_max_depth:right_max_depth;
        
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
