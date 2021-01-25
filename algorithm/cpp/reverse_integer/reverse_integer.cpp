// Source : 
// Author : Edgar Wu
// Date   : 12/24/2020
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer 
range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or 
unsigned).

 

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

Example 4:

Input: x = 0
Output: 0

 

Constraints:

    -231 <= x <= 231 - 1



*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <vector>
using namespace std;

#define INT_MIN     (-INT_MAX - 1)
#define INT_MAX      0x7FFFFFFF

class Solution {
    
#define INT_MAX     0x7FFFFFFF
#define INT_MIN     (-INT_MAX - 1)    
public:
    int reverse(int x) {
        int rem, y = 0; // reminder
        
        while(x != 0) {
            rem = x % 10;
            if (y > INT_MAX/10 || y < INT_MIN/10){
                 return 0;
            }
            y = y * 10 + rem;
            x = x /10;
        }
        
        return y;
    }
    

};

#define TEST(n, e)  printf("%12d  =>  %-12d    %s!\n",  n, sln.reverseString(n),  e == sln.reverseString(n)?"passed":"failed")

test_rev_str(const char *src, const char *dst, Solution sln) {
	string src_str(src);
	vector src_vec(src_str.begin(), src_str,end());
	string dst_str(dst);

	sln.reverseString(src_vec);

	strint res(src_vec.begin(), begin.end());
	
	printf("%12d  =>  %-12d    %s!\n",  src, res.c_str(),  res == dst_str?"passed":"failed")
}

int main()
{
	Solution sln;
	test_rev_str(123, 321, sln);
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
