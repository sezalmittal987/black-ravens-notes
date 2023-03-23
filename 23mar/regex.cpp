/*
https://leetcode.com/problems/regular-expression-matching/description/
*/

class Solution {
public:
    int dp[25][25] ;
    bool recur( string& s, string& p, int i , int j){
        // base condition
        if(i == s.length() and j == p.length()) return true;
        else if( j == p.length() ) return false;
        if( dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        // recurrence relation
        // 1. followed by a star
        if( j < p.length() - 1 and p[j+1] == '*'){
            // * = 0
            ans |= recur(s, p, i, j + 2);
            //* = 1 to * = last possible value
            int last = 0;
            for( int k = i ; k < s.length() ;k++){
                if( p[j] == '.' or p[j] == s[k]) last++;
                else break;
            } 
            for( int k = 1; k <= last ; k++){
                ans |= recur(s, p, i+k, j+2);
            }
        }
        // 2. not followed by a star
        else{
            if( p[j] == '.' or ( i < s.length() and p[j] == s[i])){
                ans |= recur(s, p, i + 1, j + 1 );
            }
            else{
                ans = false;
            }
        }
        dp[i][j] = ans;
        return ans;
    }
    bool isMatch(string s, string p) {
        for( int i = 0 ;i < 25 ; i++ ){
            for( int j = 0 ; j < 25 ; j++ ){
                dp[i][j] = -1; // value hasn't been calculated yet
            }
        }
        return recur(s, p, 0, 0);
    }
};