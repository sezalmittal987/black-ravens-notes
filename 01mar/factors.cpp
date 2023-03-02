#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n; //36
    vector<int> ans;
    for( int i = 1 ; i*i <= n ; i++ ){
        if( n%i == 0 ){
            ans.push_back(i); // 6
            if( n != i*i) ans.push_back(n/i); // 6
        }
    }
    for( int i = 0 ; i < ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}