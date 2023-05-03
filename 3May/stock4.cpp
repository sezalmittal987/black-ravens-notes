/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
*/

class Solution {
public:

    int recur( int trans, int cnt, int i, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){
        // base case
        if( i == prices.size()) return 0;
        if( dp[i][cnt][trans]!= - 1) return dp[i][cnt][trans];
        dp[i][cnt][trans] = 0;
        // buy 
        if( cnt == 0 and trans < k ) {
            dp[i][cnt][trans] = max( dp[i][cnt][trans], -prices[i] + recur(trans+ 1, 1, i + 1,k, prices, dp));
        }
        // sell
        if( cnt == 1){
            dp[i][cnt][trans] = max( dp[i][cnt][trans], prices[i]+ recur( trans, 0, i + 1,k,  prices, dp));
        }
        // no-op
        dp[i][cnt][trans] = max( dp[i][cnt][trans], recur( trans, cnt, i +1,k, prices, dp));
        return dp[i][cnt][trans];
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (2, vector<int>(k + 1, -1)));
        return recur( 0, 0, 0, k, prices, dp);
    }
};