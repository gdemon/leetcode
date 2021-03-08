// Source : 
// Author : Edgar Wu
// Date   : 08/03/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

 

Constraints:

    0 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lower-case English letters.





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
    string longestCommonPrefix(vector<string>& strs) {
        string res_prefix, tmp_prefix;
        if (strs.size() <= 0)
            return res_prefix;
        if (strs.size() == 1)
            return strs[0];
        unsigned long i, j, match;
        
        for (i = 1; i <= strs[0].size(); i++) {
            tmp_prefix = strs[0].substr(0, i);

            for (j =1 ; j < strs.size(); j++) {
                if (i > strs[j].size()) {
                    match = 0;
                    break;
                }
                
                if (tmp_prefix != strs[j].substr(0, i)) {
                    match = 0;
                    break;
                }
            }
          
            if (!match)
                return res_prefix;
            res_prefix = tmp_prefix;
        }
        
        return res_prefix;
    }
};


void verify_func(Solution &sln, vector<string> &strs, string &res) {
    string test_res = sln.longestCommonPrefix(strs); 

    if (test_res == res) {
        cout << "longestCommonPrefix()'s result is correct: " << test_res << endl;
    } else {
        cout << "longestCommonPrefix()'s result is wrong: " << test_res << "while should be: " << res << endl;
    }

}


int main(int argc, char** argv)
{
    Solution sln;

    const char* s[]={"flower","flower","flower","flower"};
    vector<string> v(s, s+4);
    string res("flower");
    verify_func(sln, v, res);

    const char* s2[]={"abab","aba","abc"};
    vector<string> v2(s2, s2+3);
    string res2("ab");
    verify_func(sln, v2, res2);

    
    return 0;

}
