/*
https://leetcode.com/problems/reverse-nodes-in-k-group/description/
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
    // start, end 
    pair<ListNode*,ListNode*> reverseList(ListNode* head) {
        ListNode *c1 = NULL, *c2 = head, *c3 = NULL;
        while(c2){
            c3 = c2->next;
            c2->next = c1;
            c1 = c2;
            c2 = c3;
        }
        return {c1, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = NULL, *st = head , *en = head , *next = head;
        while( st ){
            //isolating
            en = st;
            for( int i = 0 ; i < k - 1 ;i++){
                en = en->next;
                if( en == NULL ) return head;
            }
            next = en->next;
            if( prev ) prev->next = NULL;
            en->next = NULL;
            // reverse
            auto pr = reverseList(st);
            st = pr.first;
            en = pr.second;
            // join
            if( prev) prev->next = st;
            else head = st;
            en->next = next;
            prev = en;
            st = next;
        }
        return head;
    }
};