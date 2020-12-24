// Source : 
// Author : Edgar Wu
// Date   : 12/24/2020
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.


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
public:
    void reverseString(vector<char>& s) {
        unsigned long n = s.size(), reverse_pos;
        char tmp;
        for (int i = 0; i < n/2; i++) {
            reverse_pos = n - i - 1;
            tmp = s[i];
            s[i] = s[reverse_pos];
            s[reverse_pos] = tmp;
        }
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
