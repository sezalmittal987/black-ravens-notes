#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for( int i = 1 ;i <= n/2 ; i++ ){
        cout<<2*i<<" "<<3*i<<" ";
    }
    cout<<endl;
    int i = 1;
    while( i <= n/2 ){
        cout<<2*i<<" "<<3*i<<" ";
        i++;
    }
    cout<<endl;
}