// Source : 
// Author : Edgar Wu
// Date   : 07/03/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
The count-and-say sequence is a sequence of digit strings defined by the recursive 
formula:

    countAndSay(1) = "1"
    countAndSay(n) is the way you would "say" the digit string from 
    countAndSay(n-1), which is then converted into a different digit string.

To determine how you "say" a digit string, split it into the minimal number of 
groups so that each group is a contiguous section all of the same character. 
Then for each group, say the number of characters, then say the character. To 
convert the saying into a digit string, replace the counts with a number and 
concatenate every saying.

For example, the saying and conversion for digit string "3322251":

Given a positive integer n, return the nth term of the count-and-say sequence.

 

Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.

Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

 

Constraints:

    1 <= n <= 30



 



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
    // given a vector, return the new vector by count to say
    vector<int> get_next_vec(vector<int>& v) {
        int cnt=0;
        int val=0;
        vector<int> ret;

        for(int i=0; i<v.size(); i++){
            // the initial condition
            if (i==0){
                val = v[i];
                cnt = 1;
                continue;
            }
            
            if (v[i] == val){
                // same number => inc count
                cnt++;
            } else {
                // differnt number => reset the value and push to the return vector
                ret.push_back(cnt); 
                ret.push_back(val); 
                val = v[i];
                cnt = 1;
            }
        }
        
        // push the final set of number
        if (cnt>0 && val>0){
            ret.push_back(cnt); 
            ret.push_back(val); 
        }
        return ret;
    }
    
    string vec_to_str(vector<int> v) {
        stringstream ss;
        for (int i=0; i<v.size(); i++) {
            ss << v[i]; 
        }
        return ss.str();
    }
    
    string countAndSay(int n) {
        if (n<=0) return "";
        if (n==1) return "1";

        string ret_str;
        vector<int> v;
        v.push_back(1);
        for(int i=2; i<=n; i++)
           v = get_next_vec(v);
        
        ret_str = vec_to_str(v);
        return ret_str;
    }
    
    
};

void verify_func(Solution &sln, int& n, string &res) {
    string test_res = sln.countAndSay(n); 

    if (test_res == res) {
        cout << "countAndSay(" << n << ")'s result is correct: " << test_res << endl;
    } else {
        cout << "countAndSay(" << n << ")'s result is wrong" << endl;
    }

}


int main(int argc, char** argv)
{
    Solution sln;
    int n;
	string res;

    if (argc > 1) {
        n = atoi(argv[1]);
        cout << sln.countAndSay(n) << endl;
        return 0;
    }
    

    n = 1;
    res = "1";
	verify_func(sln, n, res);

    n = 2;
    res = "11";
	verify_func(sln, n, res);

    n = 3;
    res = "21";
	verify_func(sln, n, res);

    n = 4;
    res = "1211";
	verify_func(sln, n, res);
    
    return 0;

}
