/*
https://leetcode.com/problems/intersection-of-two-linked-lists/description/
*/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        bool f1 = false, f2 = false;
        while( p1 and p2 and p1 != p2){
            // move p1
            p1 = p1->next;
            if( !f1 and p1 == NULL) f1 = true, p1 = headB;
            // move p2
            p2 = p2->next;
            if( !f2 and p2 == NULL) f2 = true, p2 = headA;
        }
        return p1;
    }
};