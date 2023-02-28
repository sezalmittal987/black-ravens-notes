#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    string s, p;
    cin>> s >> p;
    int n = s.length();
    int m = p.length();
    vector<int> ans;
    for( int i = 0 ; i < n - m + 1 ; i++ ){
        // comparing current window to the pattern
        bool flag = true;
        for( int j = 0 ; j < m ; j++ ){
            if( s[i + j ] != p[j] ) {
                flag = false;
            }
        }
        if( flag == true ) {
            ans.push_back(i);
        }
    }
    for( int i = 0  ;i < ans.size() ; i++ ){
        cout<<ans[i]<<"  ";
    }

}