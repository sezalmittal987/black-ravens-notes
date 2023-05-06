/*
https://leetcode.com/problems/palindromic-substrings/
*/

// Solution - 1
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0 ;
        int n = s.length();
        // check all the odd length palindromes
        for( int i = 0 ; i< n ;i++){
            int l = i, r = i;
            while( l>=0 and r< n and  s[l] == s[r]) {
                l--;
                r++;
                ans++;
            }
        }

        //check all the even length palindromes
        for( int i = 0 ; i < n ; i++ ){
            int l = i, r = i + 1;
            while( l>=0 and r< n and  s[l] == s[r]) {
                l--;
                r++;
                ans++;
            }
        }

        return ans;
    }
};

// Solution -2
class Solution {
public:
    int recur( int i, int j, string& s, vector<vector<int>>& dp){
        // base cases
        if( i > j ) return 1;
        if( dp[i][j] != -1 ) return dp[i][j];
        // recurrence relation
        if( s[i] == s[j] and recur(i+1, j-1, s, dp) == 1) dp[i][j] = 1;
        else dp[i][j] = 0;
        return dp[i][j];
    }
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>>dp ( n, vector<int>(n, -1) );
        int ans = 0;
        for( int i = 0 ; i < n ; i++){
            for( int j = i ; j < n ; j++ ){
                ans += recur(i, j, s, dp) ;
            }
        }
        return ans;
    }
};

// Solution - 3
class Solution {
public:
    
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>>dp ( n, vector<int>(n, -1) );
        int ans = 0;
        for( int j = 0 ; j < n ; j++){
            for( int i = 0 ; i <= j ; i++ ){
                if( s[i] == s[j] and ( i > j - 2 or dp[i+1][j-1] == 1)) dp[i][j] = 1;
                else dp[i][j] = 0;
                ans+= dp[i][j];
            }
        }
        return ans;
    }
};


// Solution - 4- Gap Strategy
class Solution {
public:
    
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>>dp ( n, vector<int>(n, -1) );
        int ans = 0;
        for( int gap = 0 ; gap < n ; gap++){
            for( int i = 0 ; i < n-gap ; i++){
                int j = i + gap;
                if( s[i] == s[j] and ( i > j-2 or dp[i+1][j-1] == 1)) dp[i][j] = 1;
                else dp[i][j] = 0;
                ans += dp[i][j];
            }
        }
        return ans;
    }
};