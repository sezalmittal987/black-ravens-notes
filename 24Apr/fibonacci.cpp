#include<bits/stdc++.h>

using namespace std;

//Top-Down
int fibonacci(int n, vector<int>& dp){
    // base cases
    if( n == 1) return 0;
    if( n == 2) return 1;
    if( dp[n] != -1 ) return dp[n];
    dp[n] = fibonacci(n-2, dp) + fibonacci(n-1, dp);
    return dp[n];
}

// Bottom-Up
void fibonacciBU( int i, int n, vector<int>& dp){
    if( i > n ) return;
    if( i == 1 ) {
        dp[i] = 0;
    }  
    else if( i == 2 ){
        dp[i] = 1;
    }
    else dp[i] = dp[i-1] + dp[i-2];
    fibonacciBU( i +1, n, dp);
    return;
}

// Bottom-up - Iterative
int fibonacciI( int n){
    vector<int> dp(n+1, -1);
    dp[1] = 0, dp[2] = 1;
    for( int i = 3 ; i <= n ;i++ ){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// optimised space complexity
int fibonacciIO( int n){
    int dp1 = 0, dp2 = 1;
    int curr= -1;
    for( int i = 3 ; i <= n ; i++){
        curr = dp1 + dp2;
        dp1 = dp2;
        dp2 = curr;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1); 
    // cout<<fibonacci(n, dp);
    fibonacciBU(1, n, dp);
    cout<<dp[n];
    cout<<fibonacciI(n);
}