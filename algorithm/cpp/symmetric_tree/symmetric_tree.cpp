// Source : 
// Author : Edgar Wu
// Date   : 11/04/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false

 

Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    -100 <= Node.val <= 100

 
Follow up: Could you solve it both recursively and iteratively?


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
    bool isSymRecur(TreeNode *p, TreeNode *q){
        if (p==NULL && q==NULL)
            return true;

        if (p==NULL || q==NULL)
            return false;

        if (p->val != q->val)
            return false;

        if (false == isSymRecur(p->left, q->right))
            return false;

        if (false == isSymRecur(p->right, q->left))
            return false;

        return true;
    }

    bool isSymIter(TreeNode *p, TreeNode *q){

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(q1.size()>0 && q2.size()>0){
            TreeNode* p1 = q1.front();
            q1.pop();

            TreeNode* p2 = q2.front();
            q2.pop();

            if (p1==NULL && p2==NULL)
                continue;

            if (p1==NULL || p2==NULL)
                return false;
            
            if (p1->val != p2->val)
                return false;
            
            q1.push(p1->left);
            q2.push(p2->right);

            q1.push(p1->right);
            q2.push(p2->left);

        }
        return true;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if (NULL == root)
            return false;

        return isSymRecur(root->left, root->right);
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
