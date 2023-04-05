/*
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // base case
        if( inorder.size() == 0 ) return NULL;
        // find root
        int n = postorder.size();
        TreeNode* root = new TreeNode(postorder[n-1]);
        // segregate left
        vector<int> leftin, leftpost;
        int i = 0, j = 0;
        while( inorder[i]!= postorder[n-1]){
            leftin.push_back(inorder[i]);
            leftpost.push_back(postorder[j]);
            i++;
            j++;
        }

        // segregate right
        i++;
        vector<int> rightin, rightpost;
        while(i < n ){
            rightin.push_back(inorder[i]);
            rightpost.push_back(postorder[j]);
            i++;
            j++;
        }
        
        // create left subtree
        auto leftRoot = buildTree(leftin, leftpost);

        // create right subtree
        auto rightRoot = buildTree( rightin, rightpost);

        // join them
        root->left = leftRoot;
        root->right = rightRoot; 

        return root;
    }
};