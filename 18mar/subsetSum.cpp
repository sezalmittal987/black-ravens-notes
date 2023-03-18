#include<iostream>
#include<vector>

using namespace std;

// i means current element we are processing is ith
vector<vector<int>> recur( vector<int> & v, int k, int i){
    vector<vector<int>> ans;
    // 1. Base Condition
    if( k == 0 and i == v.size() ) {
        ans.push_back({});
        return ans;
    }
    if(  k != 0 and i == v.size()) {
        return ans;
    }
    // 2. Recurrence relation
    // count ith element
    if( v[i] <= k){
        vector<vector<int>> out1 = recur(v, k - v[i], i + 1); // {{2, 3}, {}}
        for( int j = 0 ; j < out1.size() ;j++){ // v[i] = 5
            out1[j].push_back(v[i]); // {2, 3, 5} | {5}
            ans.push_back(out1[j]); // ans-> {{2, 3, 5}}  | ans -> {{2,3, 5}, {5}}
        }
    }
    // don't count ith element
    vector<vector<int>> out2 = recur(v, k, i + 1); // {{1}, {1, 2}}
    for (int j = 0 ; j < out2.size(); j++){ 
        ans.push_back(out2[j]); // ans -> {{2,3, 5}, {5}, {1}} | ans -> {{2,3, 5}, {5}, {1}, {1, 2}}
    }
    return ans;
}
int main(){
    int n , k;
    cin>>n>>k ;
    vector<int> v(n);
    for( int i = 0 ; i < n ; i++ ) cin>>v[i];
    vector<vector<int>> ans = recur(v, k, 0);
    for( int i = 0;i< ans.size() ;i++){
        for ( int j = 0 ; j < ans[i].size() ;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}