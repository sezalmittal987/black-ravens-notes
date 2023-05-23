#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u;
    int v;
    int w;
};

bool compare(Edge a, Edge b){
    return a.w < b.w;
}

int findRep(int a, int* par){
    if( a == par[a] ) return a;
    return findRep(par[a], par);
}

int main(){
    int n, m;
    cin>>n>>m;
    int par[n], sz[n];
    // 0-based indexing
    for( int i = 0 ; i< n;i++){
        par[i]=i;
        sz[i] = 1;
    }
    vector<Edge> edges;
    for( int i = 0 ; i < m ; i++){
        int u, v, w;
        cin>>u>>v>>w;
        Edge e;
        e.u = u, e.v = v, e.w = w;
        edges.push_back(e);
    }
    sort(edges.begin(), edges.end(), compare); // mlogm
    int ans = 0; // cost of the MST
    // iterate all the edges in non-descending order
    for( int i = 0 ; i < m ; i++ ){ // m * log n
        int a = edges[i].u;
        int b = edges[i].v;
        int p1 = findRep(a, par);
        int p2 = findRep(b, par);
        if( p1 == p2 ) continue;
        if( sz[p1] < sz[p2]) swap(p1, p2);
        par[p2] = p1;
        sz[p1] += sz[p2];
        ans += edges[i].w;
    }
    cout<<ans<<endl;
}

// Time Complexity - O(m*(logm + log n))
// Auxiliary Space Complexity - O(n)