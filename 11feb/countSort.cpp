#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for( int i  = 0 ;i < n ; i++ ) cin>>a[i];
    int c[1001] = {};
    for( int i = 0 ; i <n ; i++ ){
        c[a[i]] += 1;
    }
    for( int i  = 0 ; i < 1001 ;i++ ){
        for( int j = 0 ; j < c[i] ;j++){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}