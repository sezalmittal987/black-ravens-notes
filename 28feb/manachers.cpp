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
    int m[z] = {};
    int l = 0,  r = 0; // left and right boundaries
    m[0] = 1;
    for( int i = 1 ; i < z ; i++){
        // inside
        if( r >= i and l < l + r - i - (m[l + r - i ] - 1)/2 ){
            m[i] = m[l + r - i];
        }
        // out or on the window
        else{
            // common part of the current palindrome and palindrome of mirrow
            if( r < i ) l = i, r = i;
            else{
                l = 2*i - r;
            }
            // expand l and r
            while( l > 0 and r  < z - 1 and a[l-1] == a[r + 1]) {
                l--;
                r++;
            }
            m[i] = r - l + 1;
        }
    }
    for( int i = 0 ; i < z ;i++){
        ans = max( ans, m[i]/2);
        cout<<m[i]<<" ";
    }
    cout<<endl<<ans<<endl;
}
