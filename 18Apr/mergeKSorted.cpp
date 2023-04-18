/*
https://leetcode.com/problems/merge-k-sorted-lists/description/
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

class comp{
    public: 
    bool operator()(ListNode* a, ListNode* b ){
        return a->val > b->val; // Min Heap
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for( int i = 0 ;i < lists.size() ; i++ ){
            if( lists[i]) pq.push(lists[i]);
        }
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            tail->next = p;
            tail = tail->next;
            if(p->next) pq.push(p->next);
        }
        return ans->next;
    }
};