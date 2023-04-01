/*
https://leetcode.com/problems/path-sum/description/
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if( !root->left and !root->right){
            if( targetSum == root->val) return true;
            else return false;
        }
        bool ans = false;
        if( root->left) ans |= hasPathSum(root->left, targetSum - root->val);
        if( root->right) ans |= hasPathSum(root->right, targetSum - root->val);
        return ans;
    }
};