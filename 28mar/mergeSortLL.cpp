/*
https://leetcode.com/problems/sort-list/description/
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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* c1 = list1, *c2 = list2, *tail = NULL, *head = NULL;
        while( c1 and c2 ){
            if( c1->val < c2->val){
                if( head == NULL ){
                    head = c1;
                    tail = head;
                }
                else{
                    tail ->next = c1;
                    tail = tail -> next;
                }
                c1 = c1 ->next;
            }
            else{
                if( head == NULL){
                    head = c2;
                    tail = head;
                }
                else{
                    tail->next = c2;
                    tail = tail -> next;
                }
                c2 = c2->next;
            }
            
        }
        if( c2 ){
            if( head == NULL) return c2;
            tail->next = c2;
        }
        if(c1){
            if( head == NULL) return c1;
            tail ->next = c1;
        }
        return head;
    }
    ListNode* mergeSort(ListNode* head){
        // base
        if( head == NULL) return head;
        if( head -> next == NULL) return head;
        // recurrence
        // find mid
        ListNode* slow = head, *fast = head, *mid = NULL;
        while( fast and fast-> next){
            mid = slow;
            slow = slow -> next;
            fast = fast->next->next;
        }
        mid -> next = NULL;
        // mergeSort left
        head = mergeSort( head);
        // mergeSort right
        slow = mergeSort(slow);
        // merge left and right
        head = merge(head, slow);
        return head;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};