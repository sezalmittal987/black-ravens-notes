#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for( int i = 0; i < n ; i++ ){
        cin>>a[i];
    }
    for( int i = 0 ; i < n/2 ; i++ ){
        swap(a[i], a[n - (i + 1)]);
    }

    // int x = n; 
    // for( int i = 0 ; i < x; i++ ){
    //     swap(a[i], a[x - 1]);
    //     x--;
    // }
    // for( int i = 0 ;i < n ;i++){
    //     cout<<a[i]<<" ";
    // }
    cout<<endl;
}