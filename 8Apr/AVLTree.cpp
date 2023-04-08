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
    int height;
    TreeNode( int _data,  TreeNode* _left = NULL, TreeNode* _right = NULL ){
        data = _data;
        left = _left;
        right = _right;
        height = 1;
    }
};

TreeNode* rightRotate(TreeNode* y){
    TreeNode* t2 = y->left->right;
    TreeNode* x = y->left;
    x->right = y;
    y->left = t2;
    y->height = 1 + max((y->left?y->left->height:0), (y->right?y->right->height:0));
    x->height = 1 + max((x->left?x->left->height:0), (x->right?x->right->height:0));
    return x;
}

TreeNode* leftRotate(TreeNode* y){
    TreeNode* t2 = y->right->left;
    TreeNode* x = y->right;
    x->left  = y;
    y->right = t2;
    y->height = 1 + max((y->left?y->left->height:0), (y->right?y->right->height:0));
    x->height = 1 + max((x->left?x->left->height:0), (x->right?x->right->height:0));
    return x;
}

// for unique nodes
TreeNode* insertNode(TreeNode* root, int key){
    if(!root){
        return new TreeNode(key);
    }
    if(key < root->data){
        root->left = insertNode(root->left, key);
    }
    else if( key > root->data) {
        root->right = insertNode(root->right, key);
    }
    else return root;
    root->height = 1 + max(((root->left)?root->left->height:0), ((root->right)?root->right->height:0));
    int bf = ((root->left)?root->left->height:0) - ((root->right)?root->right->height:0);

    // LL
    if( bf >= 2 and key < root->data ){
        root = rightRotate(root);
    }
    // RR
    else if( bf <= -2 and key > root->data){
        root = leftRotate(root);
    }
    // LR
    else if( bf >= 2 and key > root->data ){
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    // RL
    else if( bf <= -2 and  key < root->data){
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
    root->height = 1 + max(((root->left)?root->left->height:0), ((root->right)?root->right->height:0));
    return root;
}

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

void inorder(TreeNode* root){
    if( !root ) return;
    inorder(root->left);
    cout<<root->data<<" "<<((root->left)?root->left->height:0) - ((root->right)?root->right->height:0)<<" ";
    inorder(root->right);
}

void preorder (TreeNode* root){
    if( !root ) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    TreeNode* root = NULL;
    root = insertNode(root, 8);
    root = insertNode(root, 9);
    root = insertNode(root, 10);
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 6);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    vector<int> ans = levelOrderTraversal(root);
    for( int i = 0 ; i < ans.size() ;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}