/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int ans = 0;
        for( int i = 1 ; i < prices.size() ; i++){
            // selling stock on ith day
            ans = max( ans , prices[i] - mn);
            mn = min( mn, prices[i]);
        }
        return ans;
    }
};