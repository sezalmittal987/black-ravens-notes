#include<bits/stdc++.h>
using namespace std;

class Tree{
    vector<int> arr; // to store the values associated with the nodes
    vector<vector<int>> adj; // Adjacency list
    int root;

    public :
    Tree(int n, int r){
        for( int i = 0 ; i <= n ; i++ ) arr.push_back(0);
        for( int i = 0 ; i <= n ; i++) adj.push_back({});
        root = r;
    }

    void addEdge( int u, int v){ // u is the parent of v
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 

    void assignValue( int u, int x){
        arr[u] = x;
    }

    void dfs(int n, int p){
        // print root
        cout<<arr[n]<<" ";
        // call recur for children;
        for( int i = 0 ; i < adj[n].size() ;i++){
            if( adj[n][i] != p) dfs(adj[n][i], n);
        }
    }

    void bfs(){
        queue<pair<int,int>> q;
        q.push({root, -1});
        vector<int> ans;
        while(!q.empty()){
            auto x = q.front();
            int n = x.first;
            int p = x.second;
            q.pop();
            ans.push_back(arr[n]);
            for( int i = 0 ; i < adj[n].size() ; i++){
                if( adj[n][i]!= p) q.push({adj[n][i], n});
            }
        }
        for( int i = 0 ; i < ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    // subtree height
    int diameter(int n, int p, int& ans){
        int curr = 0;
        set<int> s;
        for( int i = 0 ; i < adj[n].size() ;i++){
            if( adj[n][i] != p){
                s.insert(diameter(adj[n][i], n, ans));
                if(s.size() > 2 ) s.erase(s.begin());
            }
        }
        if( s.size() == 0 ) return 0;
        if(s.size() == 1){
            ans = max( ans, *s.begin() + 1);
            return *s.begin() + 1;
        }
        int a = *s.begin();
        int b = *s.rbegin();
        ans = max( ans, a + b +2);
        return b + 1;
    }
};

int main(){
    Tree g(8, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 8);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    g.addEdge(4, 5);
    g.assignValue(1, 8);
    g.assignValue(2, 9);
    g.assignValue(3, 10);
    g.assignValue(4, 11);
    g.assignValue(5, 14);
    g.assignValue(6, 12);
    g.assignValue(7, 13);
    g.assignValue(8, 15);
    g.bfs();
    g.dfs(1, -1);

    // adjacency matrix
    int adjM[9][9] = {};
    adjM[1][2] = 1;
    adjM[1][3] = 1;
    adjM[2][4] = 1;
    adjM[3][8] = 1;
    adjM[4][6] = 1;
    adjM[4][7] = 1;
    adjM[4][5] = 1;
    cout<<endl;
    for( int i = 1 ;i <= 8 ; i++){
        for ( int j = 1 ; j <= 8 ; j++ ){
            cout<<adjM[i][j]<<" ";
        }
        cout<<endl;
    }

    int ans = 0;
    g.diameter(1, -1, ans);
    cout<<ans<<endl;
}