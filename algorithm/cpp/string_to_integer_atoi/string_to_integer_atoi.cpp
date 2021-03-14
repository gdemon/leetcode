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
        // for negative case
        // new_val = 10 * ret + digit > INT_MAX   => ovreflow => return INT_MAX
        //           10 * ret > (INT_MAX - digit)
        //                ret > (INT_MAX - digit) / 10
        
        for(; isdigit(s[i]); i++) {
            digit = (s[i] - '0');
            if(is_neg){
                if( -ret < (INT_MIN + digit)/10 ) {
                    return INT_MIN;
                }
            }else{
                if( ret > (INT_MAX - digit) /10 ) {
                    return INT_MAX;
                }
            }

            // add digit
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
