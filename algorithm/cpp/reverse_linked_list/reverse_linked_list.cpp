// Source : 
// Author : Edgar Wu
// Date   : 21/03/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given the head of a singly linked list, reverse the list, and return the reversed 
list.

 

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000

 

Follow up: A linked list can be reversed either iteratively or recursively. Could 
you implement both?

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
    ListNode* reverseListIteratively(ListNode* head) {
        // handle corner case: NULL list
        if (NULL == head)
            return head;
        ListNode *next = NULL, *cur = NULL;
        while (head) {
            next = head->next;
            // reverse
            head->next = cur;
            // move forward
            cur = head;
            head = next;
        };
        
        return cur;
    }

    ListNode* reverseListRecursively(ListNode* head) {
        // handle corner case: NULL list
        if (NULL == head)
            return head;      

        // here comes the tail, return it as the new head
        if (head->next==NULL) 
            return head;

        //        head->next->NULL
        //        head<-next
        //  NULL<-head
        ListNode *new_head = reverseListRecursively(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head;
        
    }
    ListNode* reverseList(ListNode* head) {
        //return reverseListRecursively(head);       
        return reverseListIteratively(head);
    }
};

