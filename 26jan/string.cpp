#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cout<<s.length()<<endl; // tells size of the string
    s.push_back('a');
    s.push_back('1');
    s.push_back('b');
    s.push_back('h');
    cout<<s.length()<<endl;
    for( int i = 0 ;i < 4 ; i++ ){
        cout<<s[i]<<" ";
    }
    
    cout<<endl;
    cout<<s<<endl; // outputs the string
    cin>>s; //input the string
    cout<<s<<endl;
}