/*
https://codeforces.com/contest/25/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> g[1001];
vector<pair<int, int>> rem; // to store the back-edges to rem
vector<int> add; // starting node of each component
int visited[1001] = {};
int in[1001] = {};
int cnt = 0;

void dfs( int node, int par ){
    cnt++;
    in[node] = cnt;
    visited[node]= true;
    for( auto  child : g[node]){
        if( child == par) continue;
        if( visited[child] == 1){
            if( in[child] < in[node]) rem.push_back({node, child});
        }else{
            dfs(child, node);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for( int i = 0 ; i < n- 1 ; i++ ){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for( int i = 1; i <= n ; i++){
        if(!visited[i]){
            add.push_back(i);
            dfs(i, -1);
        }
    }
    cout<<rem.size()<<endl;
    for( int i = 0 ; i < rem.size() ; i++ ){
        cout<<rem[i].first<<" "<<rem[i].second<<" "<<add[i]<<" "<<add[i+1]<<endl;
    }
}