/*
https://leetcode.com/problems/insertion-sort-list/description/
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ans = NULL;
        while( head ){
            ListNode* nn = head;
            head = head ->next;
            nn -> next = NULL;
            if( !ans){
                ans = nn;
                continue;
            }
            ListNode* curr = ans;
            ListNode* prev = NULL;
            while(curr){
                if( curr->val > nn->val){
                    if( !prev ){
                        ans = nn;
                    }else{
                        prev->next = nn;
                    }
                    nn->next = curr;
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
            if( !curr) {
                // add the nn node to the last
                prev->next = nn;
            }
        }
        return ans;
    }
};