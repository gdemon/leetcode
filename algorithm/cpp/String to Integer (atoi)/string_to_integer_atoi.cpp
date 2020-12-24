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

#define INT_MIN     (-INT_MAX - 1)
#define INT_MAX      0x7FFFFFFF

int my_atoi(const char *str) {
    if (str==NULL || *str=='\0'){
        return 0;
    }
    
    int ret=0;
    
    for(;isspace(*str); str++);
    
    bool neg=false;
    if (*str=='-' || *str=='+') {
        neg = (*str=='-') ;
        str++;
    }

    // cause we want to prevent overflow, so have to check before add digit
    // for positive case
    // new_val = 10 * ret + digit > INT_MAX   => ovreflow => return INT_MAX
    //           10 * ret > (INT_MAX - digit)
    //                ret > (INT_MAX - digit) / 10
    
    for(; isdigit(*str); str++) {
        int digit = (*str-'0');
        if(neg){
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
    
    return neg?-ret:ret;
}


int main()
{
    printf("\"%s\" = %d\n", "42", my_atoi("42"));
    printf("\"%s\" = %d\n", "123", my_atoi("123"));
    printf("\"%s\" = %d\n", "   123", my_atoi("    123"));
    printf("\"%s\" = %d\n", "+123", my_atoi("+123"));
    printf("\"%s\" = %d\n", " -123", my_atoi(" -123"));
    printf("\"%s\" = %d\n", "123ABC", my_atoi("123ABC"));
    printf("\"%s\" = %d\n", " abc123ABC", my_atoi(" abc123ABC"));
    printf("\"%s\" = %d\n", "2147483647", my_atoi("2147483647"));
    printf("\"%s\" = %d\n", "-2147483648", my_atoi("-2147483648"));
    printf("\"%s\" = %d\n", "2147483648", my_atoi("2147483648"));
    printf("\"%s\" = %d\n", "-2147483649", my_atoi("-2147483649"));
    return 0;
}
