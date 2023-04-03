/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
*/

//Solution 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    pair<bool, bool> LCA(TreeNode* root,TreeNode* p, TreeNode* q ){
        bool foundp= false ;
        bool foundq = false;
        if( root->val == p->val ) foundp = true;
        if (root->val == q->val ) foundq = true;
        pair<bool, bool>left = {false, false}, right = {false, false};
        if( root->left )  left = LCA(root->left, p, q);
        if( root->right)  right = LCA(root->right, p, q);
        foundp |= (left.first|right.first);
        foundq |= (left.second|right.second);
        if( foundp == true and foundq == true and ans == NULL) {
            
            ans = root;
        }
        return {foundp , foundq};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA(root, p, q);
        return ans;
    }
};

// Solution 2
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == NULL or p == root or q == root) return root;
        TreeNode* LeftTree = lowestCommonAncestor(root->left,p,q);
        TreeNode* RightTree = lowestCommonAncestor(root->right,p,q);
        if(LeftTree == NULL) return RightTree;
        else if(RightTree == NULL) return LeftTree;
        return root;
    }
};