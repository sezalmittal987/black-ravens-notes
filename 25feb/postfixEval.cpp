#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

bool checkOperator(string s){
    if( s == "+" or s == "-" or s == "/" or s == "*") return true;
    return false;
}
int evalPostfix(vector<string> v){
    int n = v.size();
    stack<int> s;
    int i = 0;
    while( i< n ){
        if( checkOperator(v[i]) ){
            int op1 , op2 ;
            int res = 0;
            op2 = s.top();
            s.pop();
            op1 = s.top();
            s.pop();
            if( v[i] == "+" ) res = op1 + op2;
            if( v[i] == "-" ) res = op1 - op2;
            if( v[i] == "*" ) res = op1 * op2;
            if( v[i] == "/" ) res = op1 / op2;
            s.push(res);
        }
        else{
            int num = 0 ;
            for( int j  = 0 ; j < v[i].length() ;j++){
                num = num*10 + v[i][j] - '0';
            }
            s.push(num);
        }
        i++;
    } 
    return s.top();
}

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for( int i = 0 ; i < n ; i++ ){
        cin>>v[i];
    }
    cout<<evalPostfix(v);
}