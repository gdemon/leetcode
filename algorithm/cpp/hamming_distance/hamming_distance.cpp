// Source : 
// Author : Edgar Wu
// Date   : 14/07/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

 

Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

Example 2:

Input: x = 3, y = 1
Output: 1

 

Constraints:

    0 <= x, y <= 231 - 1




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
    int count_1_bits(int n) {
        int num_bits = 0;
        for (int ; n > 0; n/=2) {
            if (n & 0x1)
                num_bits++;
        }
        return num_bits;
    }
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        return count_1_bits(z);
    }
};

int main (int argc, char** argv) {
    Solution sln;

    cout << "(1,4) == 2, :" << sln.hammingDistance(1, 4) << endl;
    
    return 0;
}












