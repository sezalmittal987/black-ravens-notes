/*
https://codeforces.com/contest/510/problem/C
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> g[26];
int visited[26] = {};
int recurStack[26] = {};
bool checkCycle = false;
vector<int>ans ;

void dfs( int node){
    visited[node] = true;
    recurStack[node] = true;
    for(auto child : g[node]){
        if( visited[child] ){
            if( recurStack[child]) checkCycle = true;
        }
        else{
            dfs(child);
        }
    }
    recurStack[node] = false;
    ans.push_back(node);
}

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for( int i = 0 ; i < n ; i++){
        cin>>v[i];
    }
    for( int i = 0 ; i < n-1 ;i++){
        // comparing i-th and i+1-th strings
        for( int j = 0 ; j < v[i].size() ; j++){
            if( v[i+1].size() == j ) {
                cout<<"Impossible"<<endl;
                return 0;
            }
            if( v[i][j] != v[i+1][j]){
                g[v[i][j]-'a'].push_back(v[i+1][j]-'a');
                break;
            }
        }
    }
    for( int i = 0 ; i <26 ; i++){
        if(!visited[i]) dfs(i);
    }
    if( checkCycle == true){
        cout<<"Impossible"<<endl;
        return 0;
    }
    reverse(ans.begin(), ans.end());
    for( auto u : ans){
        cout<<char(u+'a');
    }
    cout<<endl;

}