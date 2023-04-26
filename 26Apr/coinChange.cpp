/*
https://practice.geeksforgeeks.org/problems/coin-change2448/1
*/

class Solution {
  public:
    long long int recur( int coins[], int sum, int i, vector<vector<long long >>& dp ) {
        // base conditions
        if( sum == 0 ) return 1;
        if( i == -1 ) return 0;
        if( dp[sum][i] != -1 ) return dp[sum][i];
        int k = 0;
        dp[sum][i] = 0;
        while( k * coins[i] <=  sum ){
            dp[sum][i] += recur(coins, sum - k*coins[i], i - 1, dp);
            k++;
        }
        return dp[sum][i];
    }
    
    long long int count(int coins[], int N, int sum) {
        // code here.
        vector<vector<long long >> dp(sum +1, vector<long long >( N, -1));
        return recur(coins, sum, N-1, dp);
        
    }
};


class Solution {
  public:
  
    long long int count(int coins[], int N, int sum) {
        // code here.
        vector<vector<long long >> dp(N , vector<long long >( sum + 1, 0));
        
        for( int i = 0 ; i < N ; i++){
            for( int j = 0 ;j <= sum ;j++){
                if( i == 0 ) {
                    if( j%coins[i] == 0) dp[0][j] = 1; 
                    continue; 
                }
                int k = 0;
                while( k*coins[i] <= j ){
                    dp[i][j] += dp[i-1][j - k*coins[i]];
                    k++;
                }
            }
        } 
        return dp[N-1][sum];
        
    }
};