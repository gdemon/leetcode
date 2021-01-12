// Source : 
// Author : Edgar Wu
// Date   : 01/11/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be 
validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without
repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.

 



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
    bool isValidSudoku(vector<vector<char>>& board) {
        unsigned long r, c, idx, brd_area;
        char chr;
        
        unsigned long board_size = board.size();
        
        if (board[0].size() != board_size)
            return false;
        
        const unsigned long sudoku = 9;
        
        if (board_size != sudoku)
            return false;
        unsigned char row_valid[sudoku][sudoku] = {0};
        unsigned char col_valid[sudoku][sudoku] = {0};
        unsigned char brd_valid[sudoku][sudoku] = {0};
        
        //memset(row_valid, 0, sizeof(row_valid));
        //memset(col_valid, 0, sizeof(col_valid));
        //memset(brd_valid, 0, sizeof(brd_valid));
        
        for (r = 0; r < board_size; r++) {
            for (c = 0; c < board_size; c++) {
                chr = board[r][c];
                if(false == is_digit(chr))
                    continue;
                
                idx = chr - '0' - 1;
                
                // check row
                if (row_valid[r][idx])
                    return false;
                row_valid[r][idx] = 1;
                
                // check col
                if (col_valid[c][idx])
                    return false;
                col_valid[c][idx] = 1;
                
                // check board
                brd_area = (r/3)*3 + c/3;
                if (brd_valid[brd_area][idx])
                    return false;
                brd_valid[brd_area][idx] = 1;
            }
        }
        return true;
    }
    
    bool is_digit(char &c) {
        if (c < '0')
            return false;
        if (c > '9')
            return false;
        
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
