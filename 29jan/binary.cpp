#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, base;
    cin>>n >> base;
    vector<int> v;
    // termination condition -> n becomes 0
    // updation condition -> n /base
    while( n > 0 ){
        v.push_back(n%base);
        n /= base;
    }
    int sz = v.size();
    for ( int i = sz -1 ;i>= 0; i--){
        cout<<v[i];
    }
    // we can also reverse the vector
    cout<<endl;

} 