#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n ; //n should be odd

    //upper half
    for ( int i = 1 ; i <= n/2 ; i++ ){
        for ( int j = 1 ; j <= i ; j++ ){
            cout<<"*";
        }
        for( int j = 1 ; j <= (n - 2* i) ; j++){
            cout<<" ";
        }
        for( int j = 1; j<=i ;j++ ){
            cout<<"*";
        }
        cout<<endl;
    }

    //middle line
    for( int i =1 ; i <= n ; i++ ){
        cout<<"*";
    }
    cout<<endl;

    //lower half
    for( int i = n/2 + 2 ; i <= n ;i++ ){
        for ( int j = 1; j<= n + 1 -i ; j++){
            cout<<"*";
        }
        for (int j = 1 ; j <= 2*i -2 - n ; j++ ){
            cout<<" ";
        }
        for ( int j = 1; j<= n + 1 -i ; j++){
            cout<<"*";
        }
        cout<<endl;
    }

}