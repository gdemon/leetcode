// Source : 
// Author : Edgar Wu
// Date   : 18/04/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

 

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,3] and [3,1] are both a height-balanced BSTs.

 

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in a strictly increasing order.

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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size()==0){
            return NULL;
        }
        if(num.size()==1){
            return new TreeNode(num[0]);
        }
        int mid = num.size()/2;

        // root
        TreeNode *node = new TreeNode(num[mid]);

        // construct left child tree first
        vector<int>::const_iterator first;
        vector<int>::const_iterator last;

        first = num.begin();
        last = num.begin()+mid;
        vector<int> left_child(first, last);
        node->left = sortedArrayToBST(left_child);

        // construct right child tree then
        if (mid==num.size()-1){
            // corner case that num.size() is 2
            node->right = NULL;
        }else{
            first = num.begin()+mid+1;
            last = num.end();
            vector<int> right_child(first, last);
            node->right = sortedArrayToBST(right_child);
        }
        return node;
    }
};


