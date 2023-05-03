/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/

// solution - greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        bool flag = false;
        for( int i = 0 ; i < prices.size() ;i++ ){
            if( flag == false){
                ans -= prices[i];
                flag = true;
            }
            if( i == prices.size() - 1 or prices[i] > prices[i+1]) {
                ans += prices[i];
                flag = false;
            }
        }
        return ans;
    }
};

// solution - DP

class Solution {
public:

    int recur( int cnt, int i, vector<int>& prices, vector<vector<int>>& dp){
        // base cases
        if( i == prices.size()) return 0;
        if( dp[i][cnt] != -1) return dp[i][cnt];
        dp[i][cnt] = 0; 
        // buy
        if( cnt == 0 ){
            dp[i][cnt] = max( dp[i][cnt], -prices[i] + recur(1, i +1, prices, dp));
        }
        // sell
        if( cnt == 1 ){
            dp[i][cnt] = max( dp[i][cnt], prices[i] + recur( 0, i +1, prices, dp));
        }
        // no-op
        dp[i][cnt] = max( dp[i][cnt], recur(cnt, i +1, prices, dp));
        return dp[i][cnt];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return recur(0, 0, prices, dp);
    }
};