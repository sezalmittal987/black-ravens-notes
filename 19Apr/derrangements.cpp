#include<bits/stdc++.h>

using namespace std;

void backtrack(vector<int>& a, vector<vector<int>>& ans, vector<int> curr){
    // base condition
    if( a.size() == curr.size()){
        ans.push_back(curr);
        return;
    }
    // check all the possibilities
    for( int i = 0 ; i < a.size() ;i++ ){
        // validate -> should haven't been already used and not at the right position
        bool valid = true;
        for( int j = 0 ; j <curr.size() ;j++){
            if( curr[j] == a[i] ) valid = false;
        }
        if( curr.size() == i ) valid = false;
        if( valid){
            curr.push_back(a[i]);
            backtrack( a, ans, curr);
            curr.pop_back();
        }
    }
}

int main(){
    vector<vector<int>> ans;
    vector<int> a = {1, 2, 3};
    vector<int> curr;
    backtrack(a, ans, curr );
    for( int i = 0 ; i < ans.size() ; i++){
        for( int j = 0 ; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}