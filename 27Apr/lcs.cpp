/*
https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
*/

// solution - 1

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    int recur(int i, int j , string& s1, string& s2,vector<vector<int>>& dp ){
        if( i < 0 || j < 0 ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        if( s1[i] == s2[j] ) return dp[i][j] = 1 + recur( i-1, j-1, s1, s2, dp);
        return dp[i][j] = max(recur(i-1, j, s1, s2, dp), recur(i, j-1, s1, s2, dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp( x, (vector<int>(y, -1)));
        return recur(x-1, y-1, s1, s2, dp);
    }
};

// solution - 2

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp( x, (vector<int>(y, -1)));
        // i == 0 
        bool seen1 = false;
        for( int j = 0 ; j < y ; j++ ){
            if( s1[0] == s2[j] ) seen1 = true;
            if( seen1 == false ) dp[0][j] = 0;
            else dp[0][j] = 1;
        }
        // j == 0 
        bool seen2 = false;
        for( int i = 0 ; i < x ; i++ ){
            if( s1[i] == s2[0] ) seen2 = true;
            if( seen2 == false ) dp[i][0] = 0;
            else dp[i][0] = 1;
        }
        for( int i = 1 ; i < x ; i++ ){
            for (int j = 1 ; j < y ; j++ ){
                // fill dp[i][j]
                if( s1[i] == s2[j] ) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[x-1][y-1];
    }
};


// Solution - 3

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp( x + 1, (vector<int>(y+ 1, -1)));
        for( int i = 0 ; i <= x ; i++ ){
            for (int j = 0 ; j <= y ; j++ ){
                // fill dp[i][j]
                if( i == 0 or j == 0 ) {
                    dp[i][j] = 0;
                    continue;
                }
                if( s1[i-1] == s2[j-1] ) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
};