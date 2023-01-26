#include<iostream>
#include<string>
using namespace std;

int main(){
    string a, b;
    cin>>a>>b;
    // if( a== b){
    //     cout<<"Yes" <<endl;
    // }
    // else cout<<"No"<<endl;

    int n = a.length();
    int m = b.length();

    if( n != m ){
        cout<<"No"<<endl;
        return 0 ;
    }
    string ans = "Yes";
    for( int i =  0 ; i < n ; i++){
        if( a[i] != b[i]) ans = "No";
    }
    cout<<ans<<endl;
}