#include<iostream>
using namespace std;

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
    int x, y, m;
    cin>>x>>y>>m;
    cout<<power(x, y, m);
}