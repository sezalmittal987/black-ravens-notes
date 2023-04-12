#include<bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
    int data;
    char c;
    TreeNode* left, *right;

    TreeNode( int d = 0, TreeNode* l = NULL , TreeNode* r = NULL , char _c = '.'){
        data = d, left = l, right = r, c = _c;
    }

};


void preorder (TreeNode* root, vector<string>& order, string curr){
    if( !root ) return;
    if(!root->left and !root->right) order.push_back(curr);
    string nn = curr +'0';
    preorder(root->left, order, nn);
    nn = curr+'1';
    preorder(root->right, order, nn);
}

int main(){
    string str;
    cin>>str;
    int  n = str.length();
    int f[n] ; 
    for( int i = 0 ; i< n ; i++ ) cin>>f[i];
    multimap<int, TreeNode* > s;
    int cnt = 0;
    long long  ans = 0;
    for( long long i = 0 ; i < n ; i++ ){
        TreeNode* nn =  new TreeNode(f[i]);
        s.insert({f[i], nn });
    }
    while(s.size() > 1){
        auto it = s.begin();
        s.erase(s.begin());
        auto it2 = s.begin();
        s.erase(s.begin());
        TreeNode* nn = new TreeNode((it->first) + (it2->first), it->second, it2->second);
        s.insert({(it->first) + (it2->first), nn});
    }
    auto it = s.begin();
    auto root = it->second;
    vector<string> order; 
    string curr = "";
    preorder(root, order, curr);
    for( int i = 0 ; i < order.size(); i++ ){
        cout<<order[i]<<" ";
    }
    cout<<endl;

}