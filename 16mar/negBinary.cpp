/*
https://leetcode.com/problems/convert-to-base-2/description/
*/
class Solution {
public:
    string baseNeg2(int n) {
        if( n == 0) return "0";
        int r, q;
        string ans;
        while( n != 0 ){
            if( n%2 == 0 ) r = 0;
            else r = 1;
            if(n> 0 ){
                n = -(n/2);
            }
            else{
                n = -(n - 1)/2;
            }
            ans.push_back(r +  '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};