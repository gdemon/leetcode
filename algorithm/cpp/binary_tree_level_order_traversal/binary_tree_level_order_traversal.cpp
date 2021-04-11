// Source : 
// Author : Edgar Wu
// Date   : 11/04/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000



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
    vector<vector<int> > levelOrderRecursive(TreeNode *root) {
        vector< vector<int> > vv;
        vector<int> v;
        if (root){
            v.push_back(root->val);
            vv.push_back(v);
        }

        //divide and conquer
        vector< vector<int> > vv_left, vv_right;
        if(root && root->left) {
            vv_left = levelOrderRecursive(root->left);
        }
        if(root && root->right) {
            vv_right = levelOrderRecursive(root->right);
        }

        //merge
        for(int i=0; i<vv_left.size() || i < vv_right.size(); i++){
            if (i<vv_left.size() && i<vv_right.size()){
                vv_left[i].insert(vv_left[i].end(), vv_right[i].begin(), vv_right[i].end());
                vv.push_back(vv_left[i]);
            }else if (i<vv_left.size()) {
                vv.push_back(vv_left[i]);
            }else {
                vv.push_back(vv_right[i]);
            }
        }

        return vv;
    }

// let tree be complete sorting atree with value: 1,2,3,4,5,6,7
// The result should be [1], [2,3], [[4,5,6,7]
// initial condition: q:1, last = 1
// 1st iter: q:2,3 last=3, level = 2, vv[2] = []
// 2nd iter: q:3,4,5 last=3, level = 2, vv[2] = [2]
// 3rd iter: q:4,5,6,7 last=7, level = 3, vv[2] = [2,3], vv[3] = []
    vector<vector<int> > levelOrderIterative(TreeNode *root) {
        vector< vector<int> > vv;
        if(root == NULL) return vv;

        int level = 0; // current level.
        TreeNode *last = root; // last node of currrent level.
        // use queue to traverse tree levely
        queue<TreeNode*> q;

        q.push(root);
        vv.push_back(vector<int>());
        while(!q.empty()) {
            TreeNode *p = q.front();
            q.pop();

            vv[level].push_back(p->val);
            if(p->left ) q.push(p->left);
            if(p->right) q.push(p->right);

            // when p meets last, implies current level end
            // need to go to next level and init a new vector for next level
            if(p == last) {
                level++;
                last = q.back();
                vv.push_back(vector<int>()); // new buffer for next row.
            }
        }
        // remove the last empty vector
        vv.pop_back();

        return vv;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        return levelOrderRecursive(root);
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
