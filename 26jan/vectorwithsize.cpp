#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 5;
    vector<int> v(n);
    cout<<v.size()<<endl;
    for ( int i = 0 ;i < n ; i++ ){
        cin>>v[i];
    }
    for ( int i = 0 ;i < n ; i++ ){
        cout<<v[i];
    }
    cout<<endl;
    vector<int> a = {1, 2, 3, 4};
    cout<<a.size()<<endl;
    for( int i = 0 ;i < 4 ; i++ ){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}