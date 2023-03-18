#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> recur(string& s){
    vector<string> ans;
    // 1. base case
    if( s == "") {
        ans.push_back("");
        return ans;
    } 
    // 2. recurrence relation 
    string s1;
    if( s.length() > 1) s1 = s.substr(1);
    vector<string> prev = recur(s1);
    // not count first char
    for( int i = 0 ; i < prev.size() ;i++){
        ans.push_back(prev[i]);
    }
    // count first char
    for( int i = 0 ; i < prev.size() ;i++){
        ans.push_back(s[0] + prev[i]);
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int n = s.length();
    vector<string> ans = recur( s);
    for( int i = 0 ; i < ans.size() ;i++ ){
        cout<<ans[i]<<endl;
    }
}