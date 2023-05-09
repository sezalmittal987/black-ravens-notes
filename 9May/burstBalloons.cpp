/*
https://leetcode.com/problems/burst-balloons/description/
*/

class Solution {
public:
    int recur( int i, int j, vector<int>& v, vector<vector<int>>& dp){
        int ans = 0;
        int ld = ((i > 0)?v[i-1]:1);
        int rd = ((j < v.size()-1)? v[j+1]:1);
        if( dp[i][j]!= -1) return dp[i][j];
        for( int k = i ; k <= j ; k++){
            // kth balloon will be bursted last in this subarray
            int curr = ld*v[k]*rd;
            // left subarray
            if( i < k ) curr += recur(i, k-1, v , dp);
            // right subarray
            if( k < j ) curr += recur( k + 1, j, v, dp);
            ans = max( ans, curr);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, (vector<int>(n, -1)));
        return recur(0, nums.size() -1, nums, dp);
    }
};