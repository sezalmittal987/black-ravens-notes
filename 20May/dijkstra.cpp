#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for( int i = 0 ; i < m ; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
    int source = 1;
    // cin>>source;
    int dist[n+1] = {};
    int par[n+1] = {};
    for( int i =0 ; i < n+1; i++) dist[i] = -1;
    dist[source] = 0;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); // {dist_value, node}
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        if( dist[p.second] < p.first ) continue;
        for(auto child : adj[p.second]){
            if( dist[child.first] == -1 or  dist[child.first] > p.first + child.second){
                dist[child.first] = p.first + child.second;
                par[child.first] = p.second;
                pq.push({dist[child.first], child.first});
            }
        }
    }
    // for( int i = 1 ; i<= n ; i++) cout<<dist[i]<<" "; cout<<endl;
    if( dist[n] == -1 ){
        cout<<-1<<endl;
        return 0;
    }
    vector<int> ans;
    ans.push_back(n);
    int curr = n;
    while(par[curr] != 0 ){
        curr = par[curr];
        ans.push_back(curr);
    }
    for( int i = ans.size() - 1; i>= 0 ; i--) cout<<ans[i]<<" ";
    cout<<endl;
}