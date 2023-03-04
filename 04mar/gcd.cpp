#include<iostream>
using namespace std;

int gcd(int a, int b){
    if( b == 0 ) return a;
    return gcd(b, a%b);
}

int i_gcd( int a, int b){
    while( b > 0 ) {
        int c = b;
        b = a%b;
        a = c;
    }
    return a;
}

int lcm ( int a, int b){
    int g = gcd(a, b);
    return (a/g) * (b);
}

int main(){
    int a, b;
    cin>>a>>b;
    cout<<i_gcd(a, b)<<endl;
    cout<<lcm(a, b)<<endl;
}