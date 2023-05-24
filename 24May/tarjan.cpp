#include<bits/stdc++.h>

using namespace std;

int t = 1;
void dfs( int n, int p, vector<int>* adj, int* disc, int* low, int* ap){
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
            dfs(child, n, adj, disc, low, ap);
            if( disc[n] <= low[child] ) ap[n] = 1;
            low[n] = min( low[n], low[child]);
        }
    }
    if( p == -1 and children > 1) {
        cout<<n<<"# "<<children;
        ap[n] = 1;
    }
    return;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> adj[n + 1];
    int disc[n+1] = {};
    int low[n+1] = {};
    int ap[n+1] = {};
    // 1- based indexing
    for( int i =0 ; i < m ; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for( int i =1 ; i <= n ; i++ ){
        if( disc[i] == 0){
            cout<<i<<"$ ";
            dfs(i, -1, adj, disc, low, ap);
        }
    }
    for( int i =1 ; i <= n ; i++ ) cout<<ap[i]<<" "; 
    cout<<endl;
}