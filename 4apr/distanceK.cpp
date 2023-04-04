/*
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
*/

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
    void findInSubtree( TreeNode* root, int dist, vector<int> & ans){
        if( !root) return;
        if( dist == 0 ) ans.push_back(root->val);
        else{
            findInSubtree( root->left, dist-1, ans);
            findInSubtree( root->right, dist-1, ans);
        }  
    }

    int traverse( TreeNode* root, TreeNode* target, int k, vector<int>& ans){
        if( !root ) return -1;
        if( root == target){
            findInSubtree(root, k, ans);
            return k;
        }
        int left = traverse( root->left, target, k, ans);
        int right = traverse( root->right, target, k, ans);
        // target is in left side
        if( left > 0 ){
            // moving up
            left--;
            if( left == 0) {
                ans.push_back( root->val);
            }
            // moving down
            else{
                findInSubtree( root->right, left -1, ans);
            }
            return left;
        }
        // target is in right side
        else if ( right > 0 ){
            // moving up
            right--;
            if( right == 0) {
                ans.push_back( root->val);
            }
            // moving down
            else{
                findInSubtree( root->left, right -1, ans);
            }
            return right;
        }
        // no possible answer left
        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        traverse(root, target, k, ans);
        return ans;
    }
};