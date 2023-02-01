#include<iostream>
using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    int a[n];
    for( int i = 0 ;i < n ; i++ ){
        cin>>a[i];
    }
    // precomputed arrays
    int p[n]; // store prefix sum of array a
    p[0] = a[0];
    for( int i = 1;i< n ; i++){
        p[i] = p[i-1] + a[i];
    }
    for( int i = 0; i < n ; i++ ){
        cout<<p[i]<<" ";
    }
    int p1[n]; // store prefix sum of array p
    p1[0] = p[0];
    for (int i = 1 ;i < n ; i++){
        p1[i] = p1[i-1] + p[i];
    }
    for( int i = 0; i < n ; i++ ){
        cout<<p1[i]<<" ";
    }
    for ( int i = 0 ; i < q ;i++ ){
        int l , r;
        cin>>l>>r;
        int ans = ( r - l + 1)*p[r];
        if( r > 0 ) ans -= p1[r-1];
        if( l > 1 ) ans += p1[l-2];
        cout<<ans<<endl;
    }
}