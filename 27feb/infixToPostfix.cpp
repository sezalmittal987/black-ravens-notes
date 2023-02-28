#include<iostream>
#include<stack>
using namespace std;

int priority(char c){
    if( c == '/' ) return 2;
    if( c == '*' ) return 2;
    if( c == '+' ) return 1;
    return 1;
}

int main(){
    string s;
    cin>>s;
    int n = s.length();
    stack<char> c;
    string ans;
    for( int i = 0 ;i < n; i ++ ){
        if( s[i] >= 'a' and s[i]<= 'z'){
            ans.push_back(s[i]);
        }
        else{
            while(!c.empty() and priority(c.top()) >= priority(s[i])){
                ans.push_back(c.top());
                c.pop();
            }
            c.push(s[i]);
        }
    }
    while(!c.empty()){
        ans.push_back(c.top());
        c.pop();
    }
    cout<<ans<<endl;
}