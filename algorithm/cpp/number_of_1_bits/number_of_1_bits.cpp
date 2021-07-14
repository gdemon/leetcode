// Source : 
// Author : Edgar Wu
// Date   : 14/07/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Number of 1 Bits

Write a function that takes an unsigned integer and returns the number of '1' bits 
it has (also known as the Hamming weight).

Note:

    Note that in some languages, such as Java, there is no unsigned integer type. 
    In this case, the input will be given as a signed integer type. It should not 
    affect your implementation, as the integer's internal binary representation is 
    the same, whether it is signed or unsigned.
    In Java, the compiler represents the signed integers using 2's complement 
    notation. Therefore, in Example 3, the input represents the signed integer. -3.

 

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

Example 2:

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

Example 3:

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

 

Constraints:

    The input must be a binary string of length 32.

 
Follow up: If this function is called many times, how would you optimize it?


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
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for(; n>0; n/=2){
            // use and to test the rightmost bit
            // we divide n by 2 every iteration to shift the value to right by 1 bit
            if (n & 0x1) 
                cnt++;
        }
        return cnt;
    }
};












