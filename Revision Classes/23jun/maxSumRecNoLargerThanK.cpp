class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        // percalculation of 1-D prefix sum for each column
        int p[n][m];
        for( int j = 0 ; j < m ; j++ ){
            p[0][j] = mat[0][j];
        }
        for( int i = 1 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++ ){
                p[i][j] = p[i-1][j] + mat[i][j];
            }
        }
        int ans = INT_MIN ;
        // fix i1 and i2
        for( int i1 = 0 ; i1 < n; i1++){
            for( int i2 = i1 ; i2 < n ; i2++ ){
                set<int> s;
                s.insert(0);
                // for storing prefix sum, considering a 1-D array 
                // merging rows from i1 to i2 by summing the columns
                int curr_pre = 0;
                // fix j2
                for( int j2 = 0 ; j2 < m ; j2++){
                    curr_pre += p[i2][j2] - ((i1>0)?p[i1-1][j2]:0);
                    auto it = s.lower_bound(curr_pre - k);
                    if( it != s.end()){
                        ans = max( ans , curr_pre - (*it));
                    }
                    s.insert(curr_pre);
                }
            }
        }
        return ans;
    }
};