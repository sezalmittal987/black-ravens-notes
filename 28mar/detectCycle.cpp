/*
https://leetcode.com/problems/linked-list-cycle-ii/description/
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if( slow == fast ) {
                ListNode* p1 = head, *p2 = slow;
                while( p1 != p2){
                    p1 = p1->next;
                    p2 = p2 ->next;
                }
                return p1;
            }
        }
        return NULL;
    }
};