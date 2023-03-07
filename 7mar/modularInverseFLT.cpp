#include<iostream>
using namespace std;

int gcd(int a, int b){
    if( b == 0 ) return a;
    return gcd(b, a%b);
}


int power(int x, int y, int m){
    // base
    if( y == 0) return 1; 

    // relation
    int ans = 1;
    if( y%2 == 1 ){
        ans *= x;
        ans %= m;
    }
    int z = power(x, y/2, m);
    return (ans*((z*z)%m))%m;
}

int main(){
    int b, m;
    cin>>b>>m;
    if( gcd(b, m ) != 1) {
        cout<<-1<<endl; 
        return 0;
    }
    cout<<power(b, m-2, m)<<endl;
}