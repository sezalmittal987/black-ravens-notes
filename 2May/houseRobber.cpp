/*
https://leetcode.com/problems/house-robber-iii/description/
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
    int recur( TreeNode* root, bool rob, unordered_map<TreeNode*, int> dp[2] ){
        if( !root ) return 0;
        if( dp[rob].count(root) > 0 ) return dp[rob][root];
        dp[rob][root] = 0;
        if( rob){
            dp[rob][root] += root->val;
            dp[rob][root] += recur( root->left, false, dp);
            dp[rob][root] += recur( root->right, false, dp);
        }
        else{
            dp[rob][root] += max(recur( root->left, true, dp), recur( root->left, false, dp));
            dp[rob][root] += max(recur( root->right, true, dp), recur( root->right, false, dp));
        }
        return dp[rob][root];
    }
    int rob(TreeNode* root) {
        unordered_map< TreeNode*, int> dp[2];
        return max( recur(root, true, dp), recur(root, false, dp));
    }
};

class Solution {
public:
    void func(TreeNode* root, map<TreeNode*, int> *dp ){
        // 0 -> not counting, 1-> counting
        dp[1][root] = root->val;
        dp[0][root] = 0;
        if( root->left ) {
            func(root->left, dp);
            dp[0][root] += max( dp[0][root->left], dp[1][root->left]);
            dp[1][root] += dp[0][root->left];
        }
        if( root->right){
            func( root-> right, dp);
            dp[0][root] += max(dp[0][root->right],dp[1][root->right]);
            dp[1][root] += dp[0][root->right];
        }
    }
    int rob(TreeNode* root) {
        map<TreeNode*, int> dp[2];
        func(root, dp);
        return max( dp[0][root], dp[1][root]);
    }
};
