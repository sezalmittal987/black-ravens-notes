/*
https://leetcode.com/problems/divide-two-integers/description/
*/

class Solution {
public:
    long long multiply(long long k, long long x){
        long long ans = 0;
        for ( int i = 31 ; i >= 0 ; i--){
            if( (x&(1ll<<i)) > 0 ) {
                ans += (k<<i);
            }
        }
        return ans;
    }
    int divide(int dividend, int divisor) {
        long long n = dividend;
        long long k = divisor;
        int sign  = 1;
        if( n <= 0 and k <= 0) ;//do nothing
        else if( n >= 0 and k >= 0) ;//do nothing
        else sign = -1;
        n = abs(n);
        k = abs(k);
        long long l = 0, r = n;
        while( l < r) {
            long long mid = (l + r + 1)>>1;
            if( multiply(k, mid) <= n) l = mid ;
            else r = mid - 1;
        }
        if( sign > 0 and l >= pow(2, 31)) l = pow(2, 31) -1;
        else if( sign < 0  and l > pow(2, 31)) l = pow(2, 31);
        if( sign == 1 ) return l;
        return -l;
    }
};