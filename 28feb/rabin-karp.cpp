#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int calcHashedValue(string a){
    int m = a.length();
    int ans = 0;
    int mod = 1e6;
    for( int i  = 0 ;i < m ; i++ ){
        ans = ans*26 +  (a[i]-'a');
        ans %= mod;
    }
    return ans;
}

int power( int x, int y){
    // return x^y
    int res = 1;
    for( int i =  0 ; i < y ; i++ ){
        res *= x;
        res%= 1000000;
    }
    return res;
}

int main(){
    string s, p;
    cin>>s>>p;
    int n = s.length();
    int m = p.length();
    vector<int> ans;
    int hashp = calcHashedValue(p);
    int hashw = calcHashedValue(s.substr(0, m)); 
    bool flag = true;
    if( hashw == hashp) {
        for( int i = 0 ; i < m ; i++ ){
            if( s[i] != p[i] ) flag = false;
        }
    }
    else flag = false;
    if( flag == true) {
        // take it as an answer
        ans.push_back(0);
    }
    for( int i = 1 ; i < n -m + 1 ; i++ ){
        // remove
        hashw -= ((s[i-1]-'a')*power(26, m-1))%1000000;
        hashw = (hashw + 1000000)%1000000;
        hashw *= 26;
        // add
        hashw += (s[i+m-1] - 'a');
        hashw %= 10000000;
        cout<<hashw<<" ";
        bool flag = true;
        if( hashw == hashp) {
            for( int j = 0 ; j < m ; j++ ){
                if( s[i + j ] != p[j] ) flag = false;
            }
        }
        else flag = false;
        if( flag == true) {
            // take it as an answer
            ans.push_back(i);
        }
    }
    for( int i = 0 ; i < ans.size() ; i++ ){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}