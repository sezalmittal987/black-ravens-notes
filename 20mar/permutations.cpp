#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> permute(vector<int>& a){
    // base condition
    if( a.size() == 1 ) {
        return {{a[0]}};
    }
    // recurrence relation
    vector<vector<int>> ans;
    int n = a.size(); // a = {1,2, 3}
    for( int i = 0 ; i < n ; i++ ){ // i = 0
        vector<int> p; // remaining numbers after keeping i-th element aside
        for( int j = 0 ; j < n ; j++){ // j = 2
            if( i != j) p.push_back(a[j]); // p - {2, 3}
        }
        // call function
        vector<vector<int>> out = permute(p); // p - {2, 3} -> {{2, 3}, {3, 2}}
        for( int j = 0 ; j < out.size() ; j++){ // j = 1
            // inserting first element
            out[j].insert(out[j].begin(), a[i]); // out -  {{1, 2, 3}, {1, 3, 2}}
            // pushing the sequence into the answer
            ans.push_back(out[j]); // ans-> {{1, 2, 3}, {1, 3, 2}}
        }
    }
    // ans -> {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}}
    return ans;
}

int main(){
    int n ;
    cin>>n;
    vector<int> v(n);
    for( int i = 0 ; i < n ; i++ ){
        cin>>v[i];
    }
    vector<vector<int>> ans = permute(v);
    for( int i = 0 ; i < ans.size(); i++){
        for( int j = 0 ; j < ans[0].size() ; j++ ){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}