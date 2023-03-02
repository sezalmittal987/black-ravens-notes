#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
    // create an instance of stringstream
    stringstream s;
    // setting a string
    s.str("dfwe wfejfwh wegergr");
    // getting the string
    cout<<s.str()<<endl;
    s<<"zzzzzz";
    cout<<s.str()<<endl;
    s << "apple ";
    cout<<s.str()<<endl;
    string t;
    s>>t;
    cout<<t<<" "<<t.length()<<endl;
    s>>t;
    cout<<t<<endl;
    stringstream line;
    line.str("My name is Sezal.");
    string word; 
    while(line>>word){
        cout<<word<<" ";
    }
    // cannot iterate again
    while(line>>word){
        cout<<word<<" ";
    }
    // input
    string q;
    getline(cin, q);
    stringstream ty;
    ty.str(q);
    while(ty>>word){
        cout<<word<<" ";
    }
    cout<<q<<endl;
}