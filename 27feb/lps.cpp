#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> lpsArray(string p){
    int m = p.length();
    vector<int> lps(m);
    lps[0] = 0;
    for( int i = 1 ;i < m ; i++ ){
        if( p[i] == p[lps[i-1]] ) lps[i] = lps[i-1] + 1;
        else {
            if( p[i] == p[0]) lps[i] = 1;
            else lps[i] = 0;
        }
    }
    return lps;
}

int main(){
    string s, p;
    cin>>s >> p;
    vector<int> lps = lpsArray(p);
    for( int i = 0 ; i < lps.size(); i++ ){
        cout<<lps[i]<<" ";
    }

}