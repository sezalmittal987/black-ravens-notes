#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n], p[n] = {};
    for( int i = 0 ;i < n ; i++ ){
        cin>>a[i];
    }
    p[0] = a[0];
    // for( int i = 1 ;i < n ; i++ ){
    //     for ( int j = 0 ; j <= i ; j++ ){
    //         p[i] += a[j];
    //     }
    // }
    for( int i = 1; i < n ; i++ ){
        p[i] = a[i] + p[i-1];
    }
    for( int i = 0 ; i < n ; i++ ){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}
