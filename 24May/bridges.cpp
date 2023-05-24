#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> bridges;

int t = 1;
void dfs( int n, int p, vector<int>* adj, int* disc, int* low){
    disc[n] = t;
    low[n] = t;
    t++;
    int children = 0;
    for( auto child : adj[n]){
        if( child == p ) continue;
        if( disc[child] > 0 ){
            // there is a back edge
            low[n] = min( low[n], disc[child]);
        }
        else{
            children++;
            dfs(child, n, adj, disc, low);
            if( disc[n] < low[child] ) bridges.push_back({n, child});
            low[n] = min( low[n], low[child]);
        }
    }
    return;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> adj[n + 1];
    int disc[n+1] = {};
    int low[n+1] = {};
    // 1- based indexing
    for( int i =0 ; i < m ; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for( int i =1 ; i <= n ; i++ ){
        if( disc[i] == 0){
            dfs(i, -1, adj, disc, low);
        }
    }
    for( auto u : bridges ){
        cout<<u.first<<" "<<u.second<<endl; 
    }
    cout<<endl;
}