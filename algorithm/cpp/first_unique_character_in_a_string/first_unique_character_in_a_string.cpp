// Source : 
// Author : Edgar Wu
// Date   : 01/11/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 

Given a string, find the first non-repeating character in it and return its index. 
If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.

 

Note: You may assume the string contains only lowercase English letters.


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
    int firstUniqChar(string s) {
        const unsigned long max_ary = 256; // 256 ascii
        
        // sue char to cal this occurance, it will fail => imply test case will cause overflow for chr...
        unsigned char chr_num_ary[max_ary] = {0};
        unsigned long i;
        char chr;
        
        //memset(chr_num_ary, 0, sizeof(chr_num_ary));
        
        for (i = 0; i < s.size(); i++) {
            chr = s[i];
            if (chr_num_ary[chr] < 3)
                chr_num_ary[chr]++;
        }
            
        
        for (i = 0; i < s.size(); i++) {
            if (chr_num_ary[s[i]] == 1)
                return i;
        }
        
        return -1;
        
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
