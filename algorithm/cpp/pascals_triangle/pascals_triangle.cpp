// Source : 
// Author : Edgar Wu
// Date   : 14/07/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]


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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        int i, j, sum, row_sz;
        for (i = 0; i < numRows; i++) {
            vector<int> v;
            if (0 == i) {
                v.push_back(1);
            } else {
                v.push_back(1);
                row_sz = res[i-1].size();
                for (j = 0; j < row_sz-1; j++) {
                    sum = res[i-1][j] + res[i-1][j+1];
                    v.push_back(sum);
                }
                v.push_back(1);
            }
            res.push_back(v);
        }
        return res;
    }
};













