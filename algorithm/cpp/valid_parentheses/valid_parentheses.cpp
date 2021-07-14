// Source : 
// Author : Edgar Wu
// Date   : 14/07/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([)]"
Output: false

Example 5:

Input: s = "{[]}"
Output: true

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.



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
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        //use stack
        std::stack<char> stk;
        char sch;   //stack character
        for (auto ch : s) {
            if ('(' == ch || '[' == ch || '{' == ch) {
                stk.push(ch);
            } else {
                if (')' == ch || ']' == ch || '}' == ch) {
                    if (stk.empty())
                        return false;
                    sch = stk.top();
                    if (')' == ch && '(' != sch )
                        return false;
                    if (']' == ch && '[' != sch )
                        return false;
                    if ('}' == ch && '{' != sch )
                        return false;
                    stk.pop();
                }
            }
        }

        // the stack should be empty after itereate all the string
        if (stk.empty())
            return true;

        return false;
        
    }
};














