#include<bits/stdc++.h>
using namespace std;


void dfs(int node, int parent, vector<vector<int>>& adj, int dp[][2] ){
    dp[node][0] = 0;
    dp[node][1] = 0;
    for( auto child : adj[node]){
        if( child == parent) continue;
        dfs(child, node, adj, dp);
    }
    // node - not chosen
    for( auto child : adj[node]){
        if( child == parent) continue;
        dp[node][0] += dp[child][1];
    }

    // node - chosen
    for( auto child : adj[node]){
        if( child == parent) continue;
        dp[node][1] = max( dp[node][1] , dp[node][0] - dp[child][1] + dp[child][0] + 1);
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1, vector<int>());
    for( int i = 0 ;i < n -1 ; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dp[n+1][2];
    // no. of edges in best matching in subtree of i
    // 0 -> not choosing ith node
    // 1-> choosing ith node
    dfs(1, -1, adj, dp);
    cout<<dp[1][1]<<endl;
}