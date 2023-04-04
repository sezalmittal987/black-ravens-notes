/*
https://leetcode.com/problems/diameter-of-binary-tree/description/
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
    int ans = 0;
    int traverse(TreeNode* root){
        if( !root ) return -1;
        int left = traverse(root->left);
        int right = traverse(root->right);
        // updating answer
        ans = max( ans, left + right + 2);
        // return height of the subtree
        return max(left , right) +1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return ans;
    }
};
