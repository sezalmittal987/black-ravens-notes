#include<iostream>
using namespace std;

int ncr( int n, int k){
    int ans = 1;
    for( int i = 0 ; i < k ; i++ ){
        ans *= (n-i);
        ans /= (i + 1);
    }
    return ans;
}

int catalanNumber( int n){
    return ( ncr(2*n, n) / (n+1));
}

int recur( int n ){
    // base case
    if( n == 1) return 1;
    return (( 4*n-2)*recur(n-1))/(n+1);
}

int main(){
    int n;
    cin>>n;
    cout<<recur(n)<<endl;
}