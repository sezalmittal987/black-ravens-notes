#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    string a = "*";
    for( int i = 0 ; i < n ; i++ ){
        a.push_back(s[i]);
        a.push_back('*');
    }
    int z = a.length();
    int ans = 0 ;
    // int m[z] = {};
    for( int i = 0 ; i < z ;i++){
        int l = i ;
        int r = i;
        while( l > 0 and r < z- 1 and  a[l-1] == a[r+1]) {
            l--;
            r++;
        }
        ans = max( ans, (r-l+1)/2);
    }
    cout<<ans<<endl;
}