/*
https://leetcode.com/problems/validate-binary-search-tree/description/
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
    bool valid(TreeNode* root, int left, int right){
        if( !root ) return true;
        if( root->left){
            if( root->left->val < left or root->left->val >= root->val)  return false;
            if(!valid(root->left, left, root->val -1)) return false;
        }
        if( root->right){
            if( root->right->val > right or root->right->val <= root->val) return false;
            if(!valid(root->right, root->val + 1, right)) return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, -2147483648, 2147483647);
    }
};