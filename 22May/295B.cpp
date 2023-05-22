/*
https://codeforces.com/contest/295/problem/B
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long mat[n+1][n+1];
    for( int i = 1 ; i <= n ; i++){
        for( int j = 1 ;j <= n ; j++ ){
            cin>>mat[i][j];
        }
    }
    vector<int> x(n);
    int exist[n+1] = {};
    vector<long long> ans;
    for( int i= 0 ; i < n ; i++ ) cin >> x[i];
    for( int k = n-1 ; k >= 0 ; k-- ){
        exist[x[k]] = 1;
        for( int i = 1 ; i <= n ; i++){
            for( int j = 1 ;j<= n ; j++){
                // update mat[i][j] including x[k] in the path
                mat[i][j] = min( mat[i][j], mat[i][x[k]] + mat[x[k]][j]);
            }
        }
        long long curr = 0;
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ;j <= n ; j++){
                if( exist[i] and exist[j]) curr += mat[i][j];
            }
        }
        ans.push_back(curr);
    }
    for( int i = n-1; i >= 0 ; i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}