#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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


void inorder(TreeNode* root){
    stack<TreeNode*> s;
    s.push(root);
    while(s.top()->left) s.push(s.top()->left);
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        auto p = s.top();
        s.pop();
        if(p->right){
            s.push(p->right);
            while(s.top()->left) s.push(s.top()->left);
        }
    }
}

void preorder (TreeNode* root){
    stack<TreeNode*> s;
    s.push(root);
    cout<<root->data<<" ";
    while(s.top()->left){
        s.push(s.top()->left); 
        cout<<s.top()->data<<" ";
    }
    while(!s.empty()){
        auto p = s.top();
        s.pop();
        if(p->right){
            s.push(p->right);
            cout<<s.top()->data<<" ";
            while(s.top()->left){
                s.push(s.top()->left); 
                cout<<s.top()->data<<" ";
            }
        }
    }
}

void postorder(TreeNode* root){
    
}

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    TreeNode* six = new TreeNode(6);
    TreeNode* seven = new TreeNode(7);
    TreeNode* eight = new TreeNode(8);
    TreeNode* nine = new TreeNode(9);
    TreeNode* ten = new TreeNode(10);
    TreeNode* eleven = new TreeNode(11);
    TreeNode* twelve = new TreeNode(12);

    // add connections
    root->left = two;
    root->right = seven;
    two->left = three;
    two ->right = six;
    three->left = four;
    three ->right = five;
    seven->left = eight;
    seven->right = ten;
    eight->right = nine;
    ten->left = eleven;
    eleven->right = twelve;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
}