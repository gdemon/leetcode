// Source : 
// Author : Edgar Wu
// Date   : 12/18/2020
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

    Only the space character ' ' is considered a whitespace character.
    Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [?231,  231 ? 1]. If the numerical value is out of the range of representable values, 231 ? 1 or ?231 is returned.

*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <string>
#include <iostream>
#include <sstream>


#define INT_MIN     (-INT_MAX - 1)
#define INT_MAX      0x7FFFFFFF

using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        if (0 == s.size())
            return 0;
        
        int i, ret = 0, is_neg = 0, digit;

        // to pass begin space
        for (i=0; i<s.size();) {
            if (isspace(s[i])) {
                i++;
            } else{
                break;
            }
        }
            
        
        if ('-' == s[i] || '+' == s[i]) {
            if ('-' == s[i])
                is_neg = 1;
            i++;
        }
        cout << s << " is_neg: " << is_neg  << endl;

        // cause we want to prevent overflow, so have to check before add digit
        // for positive case
        // new_val = 10 * ret + digit > INT_MAX   => ovreflow => return INT_MAX
        //           10 * ret > (INT_MAX - digit)
        //                ret > (INT_MAX - digit) / 10

        // for negative case, but we don't check negative case although we list the equation
        // ref the comment of value part calculation.
        // new_val = 10 * ret + digit > INT_MAX   => ovreflow => return INT_MAX
        //           10 * ret > (INT_MAX - digit)
        //                ret > (INT_MAX - digit) / 10
        
        for(; isdigit(s[i]); i++) {
            digit = (s[i] - '0');
            // Check if overflow before add value.
            // to handle the very special case that input == minimum negative exactly
            // max_int = 2^31 - 1, we add the value first and we append sign value in the final 
            // e.g. if the input is -12345, we add value first untill get 12345, and append sign to get -12345
            // this way is like a mirror, +x -> -x
            // this imply the maximum negative value we can handle is from (2^31 - 1) to -(2^31 - 1) == -2^31 + 1
            // But acctaul, the minium negative value is -2^31.
            // This imply if the imput value is -2^31 exactly, the value part will be 2^31 and then overflow
            // so we just need to handl the value part only.
            // Anyway, the concept is very easy. 
            // Regardless the negative sign, if the value part if overflow, the final value is overflow too.
            // Once overflow, return INT_MIN or INT_MAX depends is its negative sign

            if( ret > (INT_MAX - digit) /10 ) {
                //value part is overflow....
                return is_neg?INT_MIN:INT_MAX;
            }

            // do not overflow, add digit
            ret = 10*ret + digit ;
        }
        
        return is_neg?-ret:ret;
    }
};



void verify_func(Solution &sln, int res, const char *test_str) {
    int test_res = sln.myAtoi(test_str); 

    if (test_res == res) {
        cout << "myAtoi()'s result is correct: " << test_res << endl;
    } else {
        cout << "myAtoi()'s result is wrong: " << test_res << " while should be: " << res << endl;
    }

}


int main() {
    Solution sln;
    verify_func(sln, 42, "42");
    verify_func(sln, 123, "123");
    verify_func(sln, 123, "   123");
    verify_func(sln, 123, "+123");
    verify_func(sln, -123, " -123");
    verify_func(sln, 123, "123ABC");
    verify_func(sln, 0, " abc123ABC");
    verify_func(sln, 2147483647, "2147483647");
    verify_func(sln, -2147483648, "-2147483648");
    verify_func(sln, 2147483648, "2147483648");
    verify_func(sln, -2147483649, "-2147483649");

    return 0;
}
