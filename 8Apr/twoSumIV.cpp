/*
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* moveNext(stack<TreeNode*>& s){
        auto p = s.top();
        s.pop();
        if(p->right){
            s.push(p->right);
            while(s.top()->left) s.push(s.top()->left);
        }
        return s.top();
    }

    TreeNode* movePrev(stack<TreeNode*>& s){
        auto p = s.top();
        s.pop();
        if( p->left){
            s.push(p->left);
            while(s.top()->right) s.push(s.top()->right);
        }
        return s.top();
    }

    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while(s1.top()->left) s1.push(s1.top()->left);
        s2.push(root);
        while(s2.top()->right) s2.push(s2.top()->right);
        TreeNode *p1 = s1.top(), *p2 = s2.top();
        while( p1 != p2 ){
            if( p1->val + p2->val < k ){
                p1 = moveNext(s1);
            }
            else if( p1->val + p2->val > k ){
                p2 = movePrev(s2);
            }
            else return true;
        }
        return false;
    }
};