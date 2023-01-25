#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    char c[n];
    for( int i = 0 ; i < n ; i++ ){
        cin>>c[i];
    }
    for ( int i = 0 ; i < n/2 ; i++ ){
        if( c[i] != c[n - (i+ 1)]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}