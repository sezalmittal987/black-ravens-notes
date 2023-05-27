#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

bool checkifEulerian(){
    // add code
    return true;
}


void dfs( int node,int n, vector<vector<int>>& mat ){
    for( int i = 1 ;i <= n ; i++ ){ 
        if( mat[node][i] > 0 ){
            mat[node][i]--;
            mat[i][node]--;
            dfs(i, n, mat);
        }
    }
    ans.push_back(node);
    return;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> mat(n+1, vector<int>(n+1, 0)); 
    for( int i = 0 ; i < m ; i++){
        int u, v;
        cin>>u>>v;
        mat[u][v]++;
        mat[v][u]++;
    }
    checkifEulerian();
    dfs(1, n, mat); // given 1 is not singlet
    for( auto x : ans) cout<<x<<" "; 
    cout<<endl;
}