/*
https://leetcode.com/problems/minimum-path-sum/description/
*/

// Solution - 1 ( Recursive )
class Solution {
public:
    int recur( int i, int j , int m, int n,vector<vector<int>>& grid, vector<vector<int>>& dp ){
        // base cases
        if( i == m-1 and j == n-1 ) return grid[i][j];
        
        if( dp[i][j]!=-1) return dp[i][j];
        // recurrence relation
        dp[i][j] = 400000;
        // down;
        if( i < m-1) dp[i][j] = min(dp[i][j], grid[i][j] + recur(i +1, j, m, n, grid, dp));
        //right
        if( j < n-1) dp[i][j] = min(dp[i][j], grid[i][j] + recur(i , j+1, m, n, grid, dp));
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp( m, vector<int>(n, -1));
        return recur(0, 0, m, n, grid, dp);
    }
};


// Solution - 2 ( Iterative )
class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp( m, vector<int>(n, 400000));
        dp[0][0] = grid[0][0];
        for( int i = 0; i < m ; i++ ){
            for( int j = 0 ;j < n ; j++){
                if( i > 0 ) dp[i][j] = min(grid[i][j] + dp[i-1][j], dp[i][j]);
                if( j > 0 ) dp[i][j] = min(grid[i][j] + dp[i][j-1], dp[i][j]);
            }
        }
        return dp[m-1][n-1];
    }
};