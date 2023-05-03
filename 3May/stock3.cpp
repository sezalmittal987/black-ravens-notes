/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
*/

class Solution {
public:

    int recur( int trans, int cnt, int i, vector<int>& prices, vector<vector<vector<int>>>& dp){
        // base case
        if( i == prices.size()) return 0;
        if( dp[i][cnt][trans]!= - 1) return dp[i][cnt][trans];
        dp[i][cnt][trans] = 0;
        // buy 
        if( cnt == 0 and trans < 2 ) {
            dp[i][cnt][trans] = max( dp[i][cnt][trans], -prices[i] + recur(trans+ 1, 1, i + 1, prices, dp));
        }
        // sell
        if( cnt == 1){
            dp[i][cnt][trans] = max( dp[i][cnt][trans], prices[i]+ recur( trans, 0, i + 1, prices, dp));
        }
        // no-op
        dp[i][cnt][trans] = max( dp[i][cnt][trans], recur( trans, cnt, i +1, prices, dp));
        return dp[i][cnt][trans];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (2, vector<int>(3, -1)));
        return recur( 0, 0, 0, prices, dp);
    }
};