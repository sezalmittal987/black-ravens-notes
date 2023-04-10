#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = 0;
    // take 5 coins
    ans += n/5;
    int x = n%5;
    // take 2 coins
    ans += x/2;
    x = x%2;
    // take 1 coins
    ans += x;
    cout<<ans<<endl;
}