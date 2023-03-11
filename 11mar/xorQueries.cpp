/*
https://leetcode.com/problems/xor-queries-of-a-subarray/description/
*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> p(n, 0);
        // compute prefix array
        p[0] = arr[0];
        for(int i = 1; i < n ; i++ ){
            p[i] = p[i-1]^arr[i];
        }
        vector<int> ans;
        // compute queries
        for ( int i = 0 ; i< queries.size() ;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if( l == 0 ) ans.push_back(p[r]);
            else ans.push_back(p[r]^p[l-1]);
        }
        return ans;
    }
};