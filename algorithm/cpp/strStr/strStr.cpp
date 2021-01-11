// Source : 
// Author : Edgar Wu
// Date   : 01/11/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().


gladabcabcggxyz
          i
    abcabcabcd
          j (fail) 	
       abcabcabcd
	      j (fail)
		  abcabcabcd


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
    //needle failure function
    vector<int> need_fail;
    
    void calc_fail_func(string &needle) {
        //by default, all of you are looser (fail)
        need_fail.assign(needle.size(), -1);
        
        int i, j;
		// j points to this one
		// i equals to failure value, but also be an index of same prefix array
		// -1 points to the index of very beginning ahead array (a virtual index), it means a total failure
		// if i points to -1, you die
        for (j = 1; j < needle.size(); j++) {
			// you are the next one want to sucess, so your success will be based on the prvious one's shoulder
            // get the first failure value of previous one
            i = need_fail[(j-1)];
            
            // fallback untill success, or till die....
            // you are either success or die
            while((needle[j] != needle[(i+1)]) && (i >= 0))
                i = need_fail[i];
            
            // update failure function only if success
            // -1 equals to an index that means fail
            
            // when will it success? stop failure.... this one == the one next to failure one
            // Even you only success one (this one == the first one), you still be success and you are the first one success
            // This means your previous one fail, but you still success.
            if (needle[j] == needle[i+1])
                need_fail[j] = i+1;
        }
        
    }
    
    int KMP(string haystack, string needle) {
        int i = 0, j = 0;
        
        while (i < haystack.size() && j < needle.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else{
                if (j==0) {
                    i++;
                } else {
                    j = need_fail[(j-1)] + 1;
                }
            }
        }
        
        if (j < needle.size()) {
            return -1;
        } else {
            // found
            return i - needle.size();
        }
    }
    
    int strStr(string haystack, string needle) {
        if (0 == needle.size())
            return 0;
        
        calc_fail_func(needle);
        return KMP(haystack, needle);
        
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
