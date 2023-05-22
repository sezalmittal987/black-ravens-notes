#include<bits/stdc++.h>
using namespace std;

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

bool check( int a, int b, int* par){
    int r1 = findRep(a, par);
    int r2 = findRep(b, par);
    return ( r1 == r2 );
}

int setCount( int* par, int  n){
    int ans = 0;
    for( int i = 0 ;i < n ;i++){
        if( i == par[i]) ans++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    // 0-based indexing 0->n-1    
    int par[n];
    int sz[n];
    // add new set
    for( int i = 0  ; i < n ; i++){
        par[i] = i;
        sz[i] = 1;
    }

    merge(1, 2, par, sz);
    merge(3, 2, par, sz);
    merge(6, 2, par, sz);
    merge(4, 5, par, sz);
    merge(7, 5, par, sz);

    cout<<check(1, 7, par)<<endl;
    cout<<findRep(11, par)<<endl;
    cout<<setCount(par, n)<<endl;

}