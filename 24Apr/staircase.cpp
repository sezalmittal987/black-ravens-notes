/*
https://leetcode.com/problems/climbing-stairs/description/
*/


// solution 1 
class Solution {
public:


    int fibonacciIO( int n){
        int dp1 = 1, dp2 = 2;
        int curr= 0;
        for( int i = 3 ; i <= n ; i++){
            curr = dp1 + dp2;
            dp1 = dp2;
            dp2 = curr;
        }
        if( n == 1) return dp1;
        return dp2;
    }
    int climbStairs(int n) {
        return fibonacciIO(n);
    }
};


// solution 2 

class Solution {
public:
    int recur(int n, vector<int>& dp){
         if( n == 1) return 1;
        if( n == 2) return 2;
        if( dp[n] != -1) return dp[n];
        return dp[n] = recur( n-1, dp) + recur(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,  -1);
        return recur(n, dp);
    }
};


// solution 3 - Matrix Exponentiation - https://www.geeksforgeeks.org/matrix-exponentiation/