/*
https://leetcode.com/problems/convert-to-base-2/description/
*/

class Solution {
public:
    string baseNeg2(int n) {
        if( n == 0) return "0";
        int k = 30;
        for( int i = 0 ; i < (1<<k) ; i++ ){
            // generate binary sequence for i
            int d = i;
            int currN = 0 ;
            string curr;
            while( d > 0 ){
                curr.push_back(d%2 + '0');
                d >>= 1;
            }
            reverse(curr.begin(), curr.end());
            // calculating decimal number with base -2
            for( int i = 0 ; i < k ; i++ ){
                currN = currN*(-2) + curr[i] - '0';
            }
            // verifying whether the current string is the answer
            if(currN == n){
                return curr;
            }
        }
        return "0";
    }
};