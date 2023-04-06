/*
https://leetcode.com/problems/delete-node-in-a-bst/description/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if( root->val == key ){
            // left, right
            if( root->left and root->right){
                TreeNode* rightSub = root->right;
                TreeNode* curr = root->left;
                while(curr->right!= NULL) curr = curr->right;
                curr->right = rightSub;
                return root->left;
            }
            else if (root->left){
                return root->left;
            }
            else if( root->right){
                return root->right;
            }
            return NULL;
        }
        TreeNode* left = root->left, *right=root->right;
        if( key < root->val )left = deleteNode(root->left, key);
        else if ( key > root->val )right = deleteNode( root->right, key);
        root->left = left;
        root->right = right;
        return root;
    }
};