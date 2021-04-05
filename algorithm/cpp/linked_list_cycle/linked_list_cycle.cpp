// Source : 
// Author : Edgar Wu
// Date   : 05/04/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false

 

Constraints:

    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9

 
Follow up: Could you do it in O(n) time and O(1) space?


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
    ListNode* findMiddle(ListNode* head) {
        ListNode *p1=head, *p2=head;
        while(p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
    // initialize
    //     prev_head  head->     head's_next
    // begin reverse
    //     prev_head  head->     tmp_next
    //     prev_head<-head       tmp_next
    // old prev_head<-prev_head<-tmp_next
    // old prev_head<-prev_head<-head
    ListNode* reverseLink(ListNode* head) {
        ListNode* prev_head = NULL, *tmp_next = NULL;
        
        while (head) {
            tmp_next = head->next;
            head->next = prev_head;
            prev_head = head;
            head = tmp_next;
        }
        return prev_head;
    }
    

    bool isPalindrome(ListNode* head) {
        if (NULL==head)
            return false;
        ListNode* pMid = findMiddle(head);
        ListNode* pRev = reverseLink(pMid); 
        // head -> ... -> pmid <- ... <- pRev
        for(;head!=pMid; head=head->next, pRev=pRev->next) {
            if (head->val != pRev->val) {
                return false;
            }
        }
        return true;
    }
};



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
