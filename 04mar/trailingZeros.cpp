/*
https://leetcode.com/problems/factorial-trailing-zeroes/description/
*/
class Solution {
public:
    int trailingZeroes(int n) {
    /* Solution 1
        int ans = 0;
        for( int i = 5 ; i <= n ; i+= 5){
            int t = i;
            // number of powers of 5
            while( t%5 == 0 ){
                t/=5;
                ans += 1;
            }
        }
        return ans;
    */
        int ans = 0;
        while(n > 0){
            ans += n/5;
            n /= 5;   
        }
        return ans;
    }
};