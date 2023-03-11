#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = 0;
    while( n > 0 ){
        // bit value
        if(n%2 == 1) ans++;
        n/=2;
    }
    cout<<ans<<endl;
}