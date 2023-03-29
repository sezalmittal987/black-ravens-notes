/*
https://leetcode.com/problems/copy-list-with-random-pointer/description/
*/

// Solution 1

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    Node* copyNext( Node* head){
        Node* chead = NULL, *tail = NULL;
        Node* curr = head;
        while( curr ){
            Node* nn = new Node(curr->val);
            if(!chead){
                chead = nn;
                tail = nn;
            }
            else{
                tail->next = nn;
                tail = nn;  
            }
            curr = curr->next;
        }
        return chead;
    }
public:
    Node* copyRandomList(Node* head) {
        if( !head) return NULL;
        // copy next links
        Node*chead = copyNext(head);
        // store association of original and copied nodes
        map<Node*, Node*> m;
        Node* c1 = head, *c2 = chead;
        while(c1 and c2){
            m[c1] = c2;
            c1 = c1->next;
            c2 = c2->next;
        }
        // copy random links
        c1 = head, c2 = chead;
        while(c1 and c2){
            if( c1->random ) c2->random = m[c1->random];
            c1 = c1->next;
            c2 = c2 ->next;
        }
        return chead;
    }
};


//Solution 2

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if( !head) return NULL;
        Node* chead = NULL;
        Node* curr = head;
        Node* curr2;
        while(curr){
            Node* nn = new Node(curr->val);
            nn ->next = curr->next;
            curr->next = nn;
            curr = curr->next->next;
            if( !chead){
                chead = nn;
                curr2 = chead;
            }
            else{            
                curr2 =  ((curr2->next)?(curr2 ->next->next):NULL);
            }
        }
        curr = head, curr2 = chead;
        while(curr){
            if( curr->random ) curr2->random = curr->random->next;
            curr = curr->next->next;
            curr2 =  ((curr2->next)?(curr2 ->next->next):NULL);
        }
        curr = head, curr2 = chead;
        while(curr and curr2){
            curr ->next = curr2->next;
            curr2->next =  ((curr2->next)?curr2 ->next->next:NULL);
            curr = curr->next;
            if( curr2 )curr2 = curr2->next;
        }
        return chead;

    }
};