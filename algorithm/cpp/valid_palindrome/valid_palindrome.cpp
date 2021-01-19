// Source : 
// Author : Edgar Wu
// Date   : 01/11/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 

Given a string, determine if it is a palindrome, considering only alphanumeric 
characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:

Input: "race a car"
Output: false

 

Constraints:

    s consists only of printable ASCII characters.




*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        unsigned long i, sz;
                
        string tgt;
        remove_noise(s, tgt);
        
        sz = tgt.size();
        for (i = 0; i < sz/2; i++ ) {
            if(tgt[i] != tgt[(sz-i-1)]) {
                return false;
            }
                
        }
        return true;
    }
    
    // remove n
    void remove_noise(string &s, string &tgt) {
        for (unsigned long i = 0; i < s.size(); i++) {
            if (::isalpha(s[i]) || ::isdigit(s[i]))
                tgt.push_back(::tolower(s[i]));
        }

    }
};

void verify_func(Solution &sln, string &haystack, string &needle) {
	int found = sln.strStr(haystack, needle);

	if (found != -1) {
		cout << "found " << needle << " in " << haystack << " on " << found << endl;
	} else {
		cout << "can't found " << needle << " in " << haystack << endl;
	}
}

int main()
{
    Solution sln;
	string haystack, needle;

	haystack = "mississippi";
    needle = "issi";
	verify_func(sln, haystack, needle);

	needle = "issip";
	verify_func(sln, haystack, needle);
		
	haystack = "babbbbbabb";
    needle = "bbab";
	verify_func (sln, haystack, needle);

    return 0;
}
