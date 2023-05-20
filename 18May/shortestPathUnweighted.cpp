#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for( int i = 0 ; i < m ; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source;
    cin>>source;
    int dist[n+1] = {};
    for( int i = 1; i<= n ; i++) dist[i] = -1; // -1 means node hasn't been marked/visited
    // bfs
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        for( auto child : adj[p]){
            if( dist[child] > -1 ) continue;
            q.push(child);
            dist[child] = dist[p] + 1;
        }
    }
    for( int i = 1 ; i <= n  ; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}