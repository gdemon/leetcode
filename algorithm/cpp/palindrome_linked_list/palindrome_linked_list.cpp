// Source : 
// Author : Edgar Wu
// Date   : 05/04/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

 

Constraints:

    The number of the nodes in the list is in the range [0, 10^4].
    -10^5 <= Node.val <= 10^5
    pos is -1 or a valid index in the linked-list.

 

Follow up: Can you solve it using O(1) (i.e. constant) memory?



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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // using a map to store the nodes we walked, o(n) space
    bool has_cycle_01(ListNode *head) {
        unordered_map<ListNode *, int> map_ptr;
        ListNode* node = head;
        
        while(NULL != node) {
            if (map_ptr.find(node) == map_ptr.end()) {
                map_ptr[node] = 1;
                node = node->next;
            } else {
                return true;
            }
        }
        return  false;
    }

    // Change the node's of value, mark the footprint by a special value, o(1) space
    // but I will not suggest this measure, it will spoil the data
    bool has_cycle_02(ListNode *head) {
        const int val_mark = 100000 + 1; // -10^5 <= Node.val <= 10^5
        ListNode* node = head;
        while(node) {
            if (node->val == val_mark) {
                return true;
            } else {
                node->val = val_mark;
                node = node->next;
            }
        }
        return false;
    }

    /*
     * if there is a cycle in the list, then we can use two pointers travers the list.
     * one pointer traverse one step each time, another one traverse two steps each time.
     * so, those two pointers meet together, that means there must be a cycle inside the list.
        o(1) space
     */
    bool has_cycle_03(ListNode *head) {
        if (head==NULL || head->next==NULL) return false;
        ListNode* fast=head;
        ListNode* slow=head;
        do{
            slow = slow->next;
            fast = fast->next->next;
        }while(fast != NULL && fast->next != NULL && fast != slow);
        return fast == slow? true : false;
    }
    bool hasCycle(ListNode *head) {
        return has_cycle_01(head);
        
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
