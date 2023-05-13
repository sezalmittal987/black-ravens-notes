#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<int>> adj;
    int N;
    public : 
    Graph(int n){
        N = n;
        for( int i = 0 ; i <= n ; i++ ) adj.push_back({});
    }

    void addEdge( int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, int* visited){
        cout<<node<<" ";
        visited[node] = true;
        for( auto child : adj[node]){
            if( visited[child]) continue;
            dfs( child, visited);
        }
    }

    void bfs(int source){
        queue<int> q;
        int visited[N+1] = {};
        q.push(source);
        visited[source] = true;
        vector<int> ans;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            ans.push_back(p);
            for( auto u : adj[p]){
                if( !visited[u] ){
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        for( int i =0 ; i < ans.size() ;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    int n, m;
    cin>>n>>m;
    Graph g(n);
    for( int i = 0 ; i < m ; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v);
    }
    // g.bfs(5);
    int visited[n+1] = {};
    for( int i = 1 ; i <= n ; i++){
        if( visited[i] == 0 ){
            g.dfs(i, visited);
        }
    }
    
}