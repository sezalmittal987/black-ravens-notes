#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int spf[n + 1] = { }; // 0 -> prime , 1 -> composite
    for( int i = 2 ; i <= n ; i++ ){
        if( spf[i] == 0 ){
            // i -> current prime factor
            spf[i] = i; 
            for( int j = i*2 ; j <= n ; j += i ){
                // if the jth element is not occupied
                if( spf[j] == 0 ) spf[j] = i;
            }
        }
    }
    // for( int i = 2 ; i <= n ; i++ ) cout<<spf[i]<<" ";
    // cout<<endl;

    // prime factorization of n
    while(n > 1){
        cout<<spf[n]<<" ";
        n /= spf[n];
    }
    cout<<endl;
}