#include<iostream>
using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    int arr[n], p[n];
    for( int i = 0; i <n ;i++){
        cin>>arr[i];
    }
    /* Solution 1
    for( int j = 0 ; j< q; j++){
        int l , r;
        cin>>l>>r;
        int sum  = 0;
        for ( int i = l-1 ; i <=r-1 ;i++ ){
            sum += arr[i];
        }
        cout<<sum<<endl;
    }
    */
    p[0] = arr[0];

   for( int i = 1; i < n ; i++ ){
        p[i] = arr[i] + p[i-1];
    }
    for( int i = 0 ; i < q ; i++ ){
        int l, r;
        cin>>l>>r;
        l--, r--;
        if( l == 0 ) cout<<p[r]<<endl;
        else cout<<p[r] - p[l-1]<<endl;
    }
    
}