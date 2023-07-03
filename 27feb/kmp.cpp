#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> lpsArray(string p){
    int m = p.length();
    vector<int> lps(m);
    lps[0] = 0;
    int j = 0;
    for( int i = 1 ;i < m ; i++ ){
        if( p[i] == p[lps[i-1]] ) lps[i] = lps[i-1] + 1;
        else {
            j = lps[i-1];
            while( j > 0 and p[j] != p[i] ){
                j = lps[j-1];
            }
            if( p[j] == p[i] ) lps[i] = (j?lps[j-1]:0) + 1;
            else lps[i] = 0;
        }
    }
    return lps;
}

int main(){
    string s, p;
    cin>>s >> p;
    vector<int> lps = lpsArray(p);
    // for( int i = 0 ; i < lps.size(); i++ ){
    //     cout<<lps[i]<<" ";
    // }
    vector<int> ans;
    int n = s.length();
    int m = p.length();
    int i = 0, j =  0;
    while( i < n){
        if( s[i] == p[j] ){
            i++;
            j++;
            if( j == m ){
                // take answer
                ans.push_back(i - m);
                // change j
                j = lps[j-1];
            }
        }
        else{
            if( j == 0 ) i++;
            else j = lps[j-1];
        }
    }
    for( int i = 0 ; i < ans.size(); i++ ){
        cout<<ans[i]<<" ";
    }

}