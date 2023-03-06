#include<iostream>
using namespace std;

int power(int x, int y){
    // base
    if( y == 0) return 1; 

    // relation
    int ans = 1;
    if( y%2 == 1 ){
        ans *= x;
    }
    int z = power(x, y/2);
    return ans*z*z;
}
int main(){
    int x, y;
    cin>>x>>y;
    cout<<power(x, y);
}