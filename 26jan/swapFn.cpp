#include<iostream>
using namespace std;

void swap1( int& c, int& d ){
    int t = c;
    c = d;
    d = t;
    cout<<c<<" "<<d<<endl;
}

int main(){
    int a, b;
    cin>>a>>b;
    swap1(a, b);
    cout<<a<<" "<<b<<endl;
}