/*
https://leetcode.com/problems/scramble-string/description/
*/

class Solution {
public:
    bool recur( int i1, int i2, int l, string& s1, string& s2, vector<vector<vector<int>>>& dp){
        int j1 = i1 + l -1;
        int j2 = i2 + l -1;
        // base cases
        if( i1 == j1 ) {
            if( s1[i1] == s2[i2]) return true;
            else return false;
        }
        if( dp[i1][i2][l]!= -1) return dp[i1][i2][l];
        // partitions
        bool ans = false;
        for( int k = i1 ; k < j1 ; k++){
            // i1->k, k+1->j
            // not scrambling
            ans |= (recur(i1, i2, k - i1 + 1, s1, s2, dp) & recur(k+1, i2 + k-i1+1, j1 - k, s1, s2, dp ));
            // scrambling
            ans |= (recur(k+1, i2, j1-k, s1, s2, dp) &recur(i1, i2 + j1-k, k - i1 + 1, s1, s2, dp));
        }
        return dp[i1][i2][l] = ans;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n, vector<int>(n+1, -1)));
        return recur(0, 0, n, s1, s2, dp);
    }
};