/*
https://leetcode.com/problems/permutation-sequence/description/
*/


class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        // prev-> number of ignored solutions occuring prior to the final solution
        long long prev = 0;
        long long f[10] = {};
        f[0] = 1;
        for( int i = 1; i <= 9 ; i++ ){
             f[i] = f[i-1]*i;
        }
        while( ans.length() < n){
            int x = n - ans.length() -1;
            for( int i = 1 ; i <= 9 ; i++){
                // should be valid
                bool valid = true;
                for( int j = 0 ;j < ans.length();j++){
                    if( i + '0' == ans[j] ) valid = false;
                }
                if(!valid) continue;
                if( prev + f[x] >= k ){
                    ans.push_back(i + '0');
                    break;
                } 
                else{
                    prev += f[x];
                }
            }
        }
        return ans;
    }
};