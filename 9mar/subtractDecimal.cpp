#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string s1, s2; //s1-s2
    cin>>s1>>s2;
    vector<int> ans;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for( int i = 0 ; i < s1.length()-s2.length() ; i++ ) s2.push_back('0');
    bool b = false; // b->false we haven't borrowed, b->true we have borrowed
    
    for( int i = 0 ; i <s2.length() ; i++ ){
        int x = 0 ;
        if( b == true) {
            if( s1[i] > '0') s1[i] -= 1, b = false;
            else s1[i] = '9';
        }
        if( s1[i] >= s2[i] ){ 
            x = s1[i]-s2[i];
        }
        else{ 
            b = true;
            x = 10 + s1[i] - s2[i];
        }
        ans.push_back(x);
    }
    reverse(ans.begin(), ans.end());
    for( int i = 0 ; i < ans.size() ; i++ ) cout<< ans[i]; cout<<endl;
}