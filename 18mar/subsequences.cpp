#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    vector<string> ans;
    // generate binary codes 0 -> 2^n - 1
    for( int i = 0 ; i < (1LL<<n) ; i++ ){ // O(2^n)
        int d = i;
        string bin ;
        // generating binary code for d
        while( d > 0 ){                     // O(n)
            if( (d&1) > 0) bin.push_back('1');
            else bin.push_back('0');
            d >>= 1;
        }
        while( bin.length() < n ) bin.push_back('0');
        reverse(bin.begin(), bin.end());
        // push a subsequence to the ans vector
        string curr;
        for ( int i = 0 ; i < n ; i++ ){            // O(n)
            if( bin[i] == '1') curr.push_back(s[i]);
        }
        ans.push_back(curr);
    }
    for( int i = 0 ; i < ans.size() ;i++ ){
        cout<<ans[i]<<endl;
    }
}