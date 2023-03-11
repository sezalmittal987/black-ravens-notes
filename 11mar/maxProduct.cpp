/*
https://leetcode.com/problems/maximum-product-of-word-lengths/description/
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> p(n, 0);
        for( int i =  0 ; i < n ;i++ ){
            for( int j = 0 ; j < words[i].length() ;j++ ){
                // set words[i][j]th bit of p[i]
                p[i] = p[i] | (1<<(words[i][j] -'a'));
            }
        }
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ){
            for ( int j= i+1 ; j < n ; j++ ){
                if( (p[i]&p[j]) == 0) ans = max( ans, int(words[i].length() * words[j].length()));
            }
        }
        return ans;
    }
};