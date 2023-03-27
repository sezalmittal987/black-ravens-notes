/*
https://leetcode.com/problems/reverse-linked-list/
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
    // head, tail
    pair<ListNode*, ListNode* > recur(ListNode* head){
        // base
        if( head == NULL or head -> next == NULL){
            return { head, head };
        }
        // recursion
        auto out = recur( head ->next);
        out.second->next = head;
        head -> next = NULL;
        return {out.first, head};
    }
    ListNode* reverseList(ListNode* head) {
        return recur(head).first;
    }
};