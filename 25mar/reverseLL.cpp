/*
https://leetcode.com/problems/reverse-linked-list/description/
*/

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
    ListNode* reverseList(ListNode* head) {
        ListNode *c1 = NULL, *c2 = head, *c3 = NULL;
        while(c2){
            c3 = c2->next;
            c2->next = c1;
            c1 = c2;
            c2 = c3;
        }
        return c1;
    }
};