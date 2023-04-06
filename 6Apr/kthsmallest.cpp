/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
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
    int ans = -1;
    // return -> count of nodes in the tree
    // updating answer
    int traverse(TreeNode* root, int k ){
        if(!root) return 0 ;
        int nl = 0, nr = 0;
        if( root->left ) nl = traverse(root->left, k);
        if( k < nl ); // answer is in left subtree;
        else{
            if( k == 1 + nl ) ans = root->val;
            else{
                nr = traverse(root->right, k - 1 - nl);
            }
        }
        return 1 + nl + nr;
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return ans;
    }
};