#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TreeNode{
    public: 
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode( int _data = 2,  TreeNode* _left = NULL, TreeNode* _right = NULL ){
        data = _data;
        left = _left;
        right = _right;
    }
};

vector<int> levelOrderTraversal(TreeNode* root){
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        auto p = q.front();
        ans.push_back(p->data);
        q.pop();
        if( p->left) q.push(p->left);
        if( p->right) q.push(p->right);
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* five = new TreeNode(5);
    TreeNode* six = new TreeNode(6);
    TreeNode* seven = new TreeNode(7);
    TreeNode* eight = new TreeNode(8);
    TreeNode* nine = new TreeNode(9);
    TreeNode* ten = new TreeNode(10);
    TreeNode* eleven = new TreeNode(11);

    // add connections
    root->left = two;
    root->right = three;
    two -> left = five;
    three -> left = six;
    three->right = seven;
    five-> left = eight;
    five->right = nine;
    six ->right = eleven;
    nine ->left = ten;

    vector<int> ans = levelOrderTraversal(root);
    for(int i = 0 ; i < ans.size(); i++ ){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}