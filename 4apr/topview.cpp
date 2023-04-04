/*
https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
*/

struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    void traverse( Node* root, int x, int y, map <int, pair<int, int>>& m){
        if(!root) return;
        if( m.count(x) and m[x].first < y ) ;
        else m[x] = {y, root->data};
        traverse(root->left, x -1, y + 1, m);
        traverse( root->right, x + 1, y + 1, m);
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        // x-value -> {y-value,node_value}
        map<int, pair <int, int>> m;
        traverse(root, 0, 0 , m);
        vector<int> ans;
        for( auto u : m){
            ans.push_back(u.second.second);
        }
        return ans;
    }

};