#include<bits/stdc++.h>

using namespace std;

void backtrack(vector<int>& a, vector<vector<int>>& ans, vector<int>& curr){
    if( curr.size() == a.size()) {
        ans.push_back(curr);
        return;
    }
    // add all the solutions to the tree
    for( int i = 0 ; i < a.size(); i++){
        // validate -> the element shouldn't be in the path already
        bool valid =true;
        for( int j = 0 ; j < curr.size(); j++ ){
            if( curr[j] == a[i]) valid = false;
        }

        if( valid){
            curr.push_back(a[i]);
            backtrack(a, ans, curr);
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