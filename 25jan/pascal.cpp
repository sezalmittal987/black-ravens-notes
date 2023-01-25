#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m[n+1][n+1];
    for ( int i = 1 ;i <= n ; i++ ){
        m[i][1] = 1;
        for( int j = 2; j <= i-1 ;j++){
            // use formula
            m[i][j] = m[i-1][j] + m[i-1][j-1];
        }
        m[i][i] = 1;
    }
    for ( int i = 1 ; i <= n ; i++ ){
        for ( int j = 1 ;j <= i; j++ ){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    for ( int i = 1; i <= n ; i++ ){
        for( int j= 1; j <= n-i ; j++ ){
            cout<<" ";
        }
        // middle part
        for( int j = 1 ; j <= i-1 ; j++ ){
            cout<<m[i][j]<<" ";
        }
        cout<<m[i][i];
        for( int j= 1; j <= n-i ; j++ ){
            cout<<" ";
        }
        cout<<endl;
    }

}