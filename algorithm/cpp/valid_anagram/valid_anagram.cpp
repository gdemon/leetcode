// Source : 
// Author : Edgar Wu
// Date   : 01/11/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?



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
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        const unsigned long ary_sz = 32;
        char map[ary_sz] = {0};
        
        unsigned long i, chr_idx, *ul_ptr;
        
        for (i = 0; i < s.size(); i++ ) {
            chr_idx = s[i] - 'a';
            map[chr_idx]++;
        }
        
        for (i = 0; i < t.size(); i++ ) {
            chr_idx = t[i] - 'a';
            map[chr_idx]--;
        }
        
        // 8ms, 81.62%
        for(i = 0; i < ary_sz; i++) {
            if (map[i])
                return false;
        }

        // 4ms, 98.8%, cause we reduce loop count here, but it's not a clear code
        // even it will be faster, I will not choose it in real implemenation.
        /*
        ul_ptr = (unsigned long *)map;
        for(i = 0; i < (ary_sz / sizeof(unsigned long)); i++) {
            if (*ul_ptr)
                return false;
            
            ul_ptr++;
        }
        */
        
        return true;
                
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
