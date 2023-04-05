/*
https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        TreeNode* nn = new TreeNode(val);
        if(!curr) return nn;
        
        while( curr){
            if( curr->val > val) {
                if( curr->left) curr = curr->left;
                else {
                    curr->left = nn;
                    return root;
                }
            }
            else{
                if(curr->right) curr = curr->right;
                else {
                    curr->right = nn;
                    return root;
                }
            }
        }
        
        return root;
    }
};