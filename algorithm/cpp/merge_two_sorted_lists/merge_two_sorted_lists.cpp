// Source : 
// Author : Edgar Wu
// Date   : 21/03/2021
// Tihs onw is written by myself

/********************************************************************************** 
* 
Merge two sorted linked lists and return it as a sorted list. The list should be 
made by splicing together the nodes of the first two lists.

 

Example 1:

Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: l1 = [], l2 = []
Output: []

Example 3:

Input: l1 = [], l2 = [0]
Output: [0]

 

Constraints:

    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both l1 and l2 are sorted in non-decreasing order.



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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *tail;
        
        // handle corner case first;
        if (NULL == l1 && NULL == l2)
            return l1;
        if (NULL == l1)
            return l2;
        if (NULL == l2)
            return l1;
        
        // determine head first;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        tail = head;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        
        if (l1)
            tail->next = l1;
        if (l2)
            tail->next = l2;
            
        return head;
    }
};

