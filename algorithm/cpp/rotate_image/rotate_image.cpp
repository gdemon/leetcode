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


   0   1   2   3
0 0,0 0,1 0,2 0,3
1 1,0 1,1 1,2 1,3
2 2,0 2,1 2,2 2,3
3 3,0 3,1 3,2 3,3

0,0 -> tmp
3,0 -> 0,0 (to top)
3,3 -> 3,0 (to left)
0,3 -> 3,3 (do bottom)
tmp -> 0,3 (to right)



*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <vector>
#include <string>
#include <iostream>

using namespace std;

void rotate(vector<vector<int> > &matrix) {

    int n = matrix.size();

    for( int i=0; i<n/2; i++ ){
        int low=i, high=n-i-1;
        for (int j=low; j<high; j++){
            int tmp;
            tmp = matrix[i][j];
            // left to top 
            matrix[i][j] = matrix[n-j-1][i];
            // bottom to left
            matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
            // right to bottom
            matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
            // top to right
            matrix[j][n-i-1] = tmp;
        }
    }
}








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
