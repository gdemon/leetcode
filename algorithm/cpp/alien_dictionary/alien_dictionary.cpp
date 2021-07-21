// Source : 
// Author : Edgar Wu
// Date   : 21/07/2021
// Rewrite by myself, but some will be refered from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
This problem is leetcode primium and interviewed by many popluar compang like FANNG.
Ref solution here and will rewrite in the furture   :
https://www.youtube.com/watch?v=5slT8ZfVKrQ
https://github.com/gzc/leetcode/blob/master/cpp/261-270/Alien%20Dictionary.cpp



There is a new alien language which uses the latin alphabet. However, the order 
among letters are unknown to you. You receive a list of non-empty words from the 
dictionary, where words are sorted lexicographically by the rules of this new language. 
Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"

Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"

Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

Explanation: The order is invalid, so return "".

Note:

    You may assume all letters are in lowercase.
    You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
    If the order is invalid, return an empty string.
    There may be multiple valid order of letters, return any one of them is fine.

Difficulty:
Hard 


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
    bool dfs(char ch,
             unordered_map<char, vector<char>>& graph,
             unordered_map<char, int>& colors,
             string& order) {
        colors[ch] = 1;
        for (char neighbor : graph[ch]) {
            if (colors[neighbor] == 1) {
                return true;
            }
            if (colors[neighbor] == 0) {
                bool has_circle = dfs(neighbor, graph, colors, order);
                if (has_circle) {
                    return true;
                }
            }
        }
        order.push_back(ch);
        colors[ch] = 2;
        return false;
    }
    
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        for (int i = 1; i < words.size(); i++) {
            int len = min(words[i-1].size(), words[i].size());
            for (int j = 0; j < len; j++) {
                if (words[i-1][j] != words[i][j]) {
                    graph[words[i-1][j]].push_back(words[i][j]);
                    break;
                }
                if (j == len - 1 && words[i].size() < words[i-1].size()) {
                    return "";
                }
            }
        }
        
        unordered_map<char, int> colors;
        for (const string& word : words) {
            for (char ch : word) {
                colors[ch] = 0;
            }
        }
        
        string res;
        for (const auto& [ch, color] : colors) {
            if (color == 0) {
                if (dfs(ch, graph, colors, res)) {
                    return "";
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
















