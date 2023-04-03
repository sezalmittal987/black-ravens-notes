#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TreeNode{
    public: 
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;
    int depth;
    int heightS;

    TreeNode( int _data = 2,  TreeNode* _left = NULL, TreeNode* _right = NULL ){
        data = _data;
        left = _left;
        right = _right;
    }
};

int Tdepth = 0 ; 
// depth of a node, height of the subtree
int findDepthHeightS(TreeNode* root, int depth){
    if(!root) return;
    root->depth = depth;
    int leftH = findDepthHeightS(root->left, depth + 1);
    int rightH = findDepthHeightS(root->right, depth + 1);
    Tdepth = max(depth, Tdepth);
    root->heightS = max( leftH, rightH ) + 1;
    return root->heightS;
}

// height of the node
void findHeight(TreeNode* root){
    if(!root) return;
    root->height = Tdepth - root->depth;
    findHeight(root->left);
    findHeight(root->right);
}