#include<bits/stdc++.h>
using namespace std;

void dfs( int node, vector<int>* adj, int* sub){
    sub[node] = 1;
    for( auto child : adj[node]){
        dfs( child , adj, sub);
        sub[node] += sub[child];
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for( int i = 2 ; i <= n ; i++ ){
        int parent;
        cin>>parent;
        adj[parent].push_back(i);
    }
    int sub[n+1]= {};
    dfs(1, adj, sub);
    for( int i = 1;i <=n ; i++){
        cout<<sub[i] -1 <<" ";
    }
    cout<<endl;
}