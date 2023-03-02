#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n + 1] = { }; // 0 -> prime , 1 -> composite
    for( int i = 2 ; i <= n ; i++ ){
        if( a[i] == 0 ){
            cout<<i<<" ";
            for( int j = i*2 ; j <= n ; j += i ){
                a[j] = 1;
            }
        }
    }
    cout<<endl;
}