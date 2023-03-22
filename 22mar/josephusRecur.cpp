#include<iostream>
using namespace std;

int recur(int n , int k){
    if( n == 1) return 0;
    return (recur((n-1),k) + k)%n;
}
int main(){
    int t, k;
    cin>>t>>k;
    cout<<recur(t, k) + 1<<endl;
}