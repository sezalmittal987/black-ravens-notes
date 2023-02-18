#include<iostream>
#include<unordered_map>

using namespace std;
 
int main(){
    int n , m, x;
    cin>>n>>m>>x;
    int a[n], b[m];
    unordered_map<int, int> um;
    for( int i = 0 ; i < n ; i++ ) cin>>a[i];
    for( int i = 0 ; i < m ; i++ ) cin>>b[i];
    // store all the values in B in hash map
    for( int i  = 0 ; i < m ; i++ ){
        um[b[i]] = i;
    }
    for( int i = 0 ; i < n ; i++ ){
        auto it = um.find(x - a[i]);
        if( it != um.end() ) {
            cout<<i<<" "<<it->second<<endl;
        }
    }
}