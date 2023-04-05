/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/928579899/
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
    // head and tail of the LL
    pair<TreeNode*, TreeNode*> traverse(TreeNode* root){
        if( !root ) return {NULL, NULL};
        // flatten left subtree
        auto left = traverse(root->left);
        // flatten right subtree
        auto right = traverse(root->right);
        // join
        // root->left->right
        
        if( root->left and root->right){
            root->left = NULL;
            root->right = left.first;
            left.second->right = right.first;
            right.second->right = NULL;  
            return {root, right.second};    
        }
        else if( root->left){
            root->left = NULL;
            root->right = left.first;
            left.second->right = NULL;
            return {root, left.second};
        }
        else if( root->right){
            root->left = NULL;
            root->right = right.first;
            right.second->right = NULL;
            return {root, right.second};
        }
        return {root, root};
    }
    void flatten(TreeNode* root) {
        traverse(root);
    }
};