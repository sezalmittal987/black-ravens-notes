#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    string s;
    cin>>s;
    int k; 
    cin>>k;
    /* Solution 1 
    int cnt[26] = {};
    for( int i = 0 ; i < s.length() ; i++ ){
        cnt[s[i]-'a']++; // s[i] = 'a', 'a'-'a' = 0, 'b' - 'a' = 1, 'c' - 'a' = 2
    }
    for( int i = 0 ;i < 26 ;i++ ){
        if( cnt[i] >= k ){
            cout<<char(i + 'a')<<endl;
        }
    }
    */
    unordered_map<char, int> m;
    for( int i  = 0 ; i < s.length(); i++ ){
        m[s[i]]+= 1;
    }
    for( auto u : m ){
        if( u.second >= k){
            cout<<u.first<<endl;
        }
    }
}