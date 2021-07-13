// Source : 
// Author : Edgar Wu
// Date   : 14/07/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two one's added together. 
12 is written as XII, which is simply X + II. The number 27 is written as XXVII, 
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, 
the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. The same principle 
applies to the number nine, which is written as IX. There are six instances where 
subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3

Example 2:

Input: s = "IV"
Output: 4

Example 3:

Input: s = "IX"
Output: 9

Example 4:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 5:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

 

Constraints:

    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999].



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
private:
    int romanCharToInt(char ch){
        int d = 0;
        switch(ch){
            case 'I':  
                d = 1;  
                break;  
            case 'V':  
                d = 5;  
                break;  
            case 'X':  
                d = 10;  
                break;  
            case 'L':  
                d = 50;  
                break;  
            case 'C':  
                d = 100;  
                break;  
            case 'D':  
                d = 500;  
                break;  
            case 'M':  
                d = 1000;  
                break;  
        }
        return d;
    }
public:
    int romanToInt(string s) {
        if (s.size()<=0) return 0;
        int result = romanCharToInt(s[0]);
        for (int i=1; i<s.size(); i++){
            int prev = romanCharToInt(s[i-1]);
            int curr = romanCharToInt(s[i]);
            //if left<right such as : IV(4), XL(40), IX(9) ...
            // we have to substract prev when prev < curr
            // In this case, (prev and curr) forms pair to show a real value == curr - prev.
            // But in the previous loop, the prev has been already added into the result.
            // That's why we have to substract back beacuse it can't be added in this case.
            if (prev < curr) {
                result = result - prev + (curr-prev);
            }else{
                result += curr;
            }
        }
        return result;
    }
};



int main(int argc, char**argv)
{
    string s("XL");
    if (argc>1){
        s = argv[1];
    }
    Solution sln;
    cout << s << " : " << sln.romanToInt(s) << endl;
    return 0;
}











