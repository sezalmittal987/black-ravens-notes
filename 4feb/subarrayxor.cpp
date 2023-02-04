#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n ; i ++)cin>>a[i];
    int sum = 0;
    for( int i =0 ; i< k ; i++ ){
        sum ^= a[i];
    }
    int ans = sum;
    cout<<sum<<" ";
    for( int i = 0 ; i < n-k ;i++){
        sum = (sum ^ (a[i] ^ a[i + k]));
        cout<<sum<<" ";
        ans = max(ans, sum);
    }
    cout<<endl;
    cout<<ans<<endl;
}