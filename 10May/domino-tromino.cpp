/*
https://leetcode.com/problems/domino-and-tromino-tiling/
*/

// Solution - 1
class Solution {
public:
    int numTilings(int n) {
        int dp[n+1];
        dp[1] = 1;
        if( n == 1) return dp[1];
        dp[2] = 2;
        if( n == 2 ) return dp[2];
        dp[3] = 5;
        int mod = 1000000007;
        for( int i = 4 ; i<= n ; i++){
            dp[i]=( (2*dp[i-1])%mod + dp[i-3])%mod;
        }
        return dp[n];
    }
};

// Solution - 2
class Solution {
public:
    int numTilings(int n) {
        int dp[n+1][3];
        // 0-> up
        // 1-> down
        // 2-> column
        dp[0][0] = dp[0][1] = 0;
        dp[0][2] = 1;
        dp[1][0] = dp[1][1] = 0;
        dp[1][2] = 1;
        int mod = 1000000007;
        for( int i = 2 ; i<= n ; i++){
            dp[i][2] = (((dp[i-1][2] + dp[i-1][0])%mod + dp[i-1][1])%mod + dp[i-2][2])%mod;
            dp[i][1] = dp[i-1][0] + dp[i-2][2];
            dp[i][0] = dp[i-1][1] + dp[i-2][2];
            dp[i][1] %= mod;
            dp[i][0] %= mod;
        }
        return dp[n][2];
    }
};