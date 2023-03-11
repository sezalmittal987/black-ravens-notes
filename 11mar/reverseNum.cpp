/*
https://leetcode.com/problems/reverse-bits/description/
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string b;
        while( n > 0 ){
            b.push_back((n&1) + '0');
            n /= 2;
        }
        while( b.length() < 32 ) b.push_back('0');
        uint32_t ans = 0;
        for( int i = 0 ; i <= 31 ; i++){
            ans <<= 1;
            ans += b[i]-'0';
        }
        return ans;
    }
};

// Solution 2
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int len = 0;
        while( n > 0 ){
            ans <<= 1;
            ans += (n&1);
            n /= 2;
            len++;
        }
        while( len < 32 ) ans<<=1, len++;
        return ans;
    }
};