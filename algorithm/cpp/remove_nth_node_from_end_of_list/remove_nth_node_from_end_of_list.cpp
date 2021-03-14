// Source : 
// Author : Edgar Wu
// Date   : 14/03/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and 
return its head.

Follow up: Could you do this in one pass?

 

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

 

Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz


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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (NULL == head)
            return NULL;
        if (0 >= n)
            return NULL;
        
        ListNode virtual_head(0);
        ListNode *p1, *p2;
        virtual_head.next = head;
        head = &virtual_head;
        // we need virtual head because sometimes head the element that we need to delete
        p1 = head;
        p2 = head;

        // there is (n-1) distance from the tail to the nth element, so we move p2 for n distance.
        for (int i = 0; i < n; i++) {
            if (NULL == p2)
                return NULL;
            p2 = p2->next;
        }
        
        // now p1 and p2 has n distance, move them simultaneously untill p2 reach tail
        // then p1's next points to the nth element from tail
        // p1 - tail == n, p1->next - tail == n-1
        while (NULL != p2->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        // now p2 reach the tail element, so we need to the p1's next
        // even the nth element is head, it is okay because p1 now stays at virtual head
        p1->next = p1->next->next;
        return head->next;
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
