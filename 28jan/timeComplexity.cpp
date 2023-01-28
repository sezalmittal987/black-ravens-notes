#include<iostream>
using namespace std;

void func(int n){
    for( int i = 0; i < n ; i++ ){
        cout<< i<<" ";
    }
}

int main(){
    int n ;
    cin>>n;
    if( n%2 == 0){
        func(n);
    }

    for ( int i = 1 ; i < n ; i*= 2){
        for ( int i = 1 ; i < n ; i += 2 ){
            func(n);
            func(n);
        }
    }
}