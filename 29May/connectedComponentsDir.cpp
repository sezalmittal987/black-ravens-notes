// N o of connected components in the given directed graph - using DSU

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];


// DSU 

int findRep(int a, int* par){
    if( a == par[a] ) return a;
    return findRep(par[a], par);
}

void merge(int a, int b, int* par, int* sz){
    int r1 = findRep(a, par);
    int r2 = findRep(b, par);
    if( r1 == r2) return;
    if( sz[r1] < sz[r2]) swap(r1, r2);
    par[r2] = r1;
    sz[r1] += sz[r2];
}

int setCount( int* par, int  n){
    int ans = 0;
    for( int i = 0 ;i < n ;i++){
        if( i == par[i]) ans++;
    }
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    // 0- based indexing
    int par[n], sz[n];
    for( int i = 0; i < n ; i++ ){
        par[i] = i;
        sz[i] =1;
    }
    for( int i = 0 ; i < m ; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        merge(u, v, par, sz);
    }
    
    cout<<setCount(par, n);
}