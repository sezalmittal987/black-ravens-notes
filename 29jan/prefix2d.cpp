#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int arr[n][m], p[n][m];
    for( int i = 0 ;i < n ; i++ ){
        for( int j = 0 ;j < m ; j++ ){
            cin>>arr[i][j];
        }
    }
    p[0][0] = arr[0][0];
    for( int j = 1 ; j < m ; j++ ){
        p[0][j] = p[0][j-1] + arr[0][j]; 
    }
    for( int i = 1 ; i < n ; i++  ){
        p[i][0] = p[i-1][0] + arr[i][0]; 
    }
    for( int i = 1 ;i < n ; i++ ){
        for( int j = 1 ;j < m ; j++ ){
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + arr[i][j];
        }
    }
    for( int i = 0 ;i < n ; i++ ){
        for( int j = 0 ;j < m ; j++ ){
            cout<< p[i][j]<<" ";
        }
        cout<<endl;
    }
}