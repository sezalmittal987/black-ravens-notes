/*
https://leetcode.com/problems/edit-distance/description/
*/

// solution - 1
class Solution {
public:
    int recur(string& s1, string& s2, int i , int j, vector<vector<int>>& dp ){
        // base case
        if( i == -1 and j == -1 ) return 0;
        if( i == -1 and j >= 0  ) return j + 1;
        if( j == - 1 and i >= 0) return i + 1; 
        
        if( dp[i][j] != - 1) return dp[i][j];
        dp[i][j] = max(s1.length(), s2.length());
        //no -op
        if( s1[i] == s2[j] ){
            dp[i][j] = min(dp[i][j], recur(s1, s2, i-1, j-1, dp));
        }

        // replace
        dp[i][j] = min( dp[i][j], 1 + recur(s1, s2, i-1, j-1, dp));

        // delete
        dp[i][j] = min( dp[i][j], 1 + recur(s1, s2, i-1, j, dp));

        // insert
        dp[i][j] = min( dp[i][j], 1+ recur(s1, s2, i, j-1, dp));
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return recur( word1, word2, word1.length() -1, word2.length() - 1, dp);
    }
};

// solution - 2

class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.length(),n=s2.length(),i,j;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(i = 0; i <= m; i++){
            for(j = 0; j <= n; j++){
                if(i==0&&j==0){
                    dp[i][j] = 0;
                }else if(i==0){
                    dp[i][j] = j;
                }else if(j==0){
                    dp[i][j] = i;
                }
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[m][n];
    }
};