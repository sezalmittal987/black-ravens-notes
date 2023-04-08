/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* p1, *p2;
        p1 = root->left, p2 = root->right;
        // adding links
        while(p1 and p2){
            p1->next = p2;
            p1= p1->right;
            p2 = p2->left;
        }
        // left subtree
        connect(root->left);
        //right subtree
        connect(root->right);
        return root;
    }
};