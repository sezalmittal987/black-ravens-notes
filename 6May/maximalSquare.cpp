/*
https://leetcode.com/problems/maximal-square/description/

*/
// Time-Complexity : m*n*log(min(m,n))
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // prefix sum array
        vector<vector<int>> p ( m, vector<int>(n, 0));
        p[0][0] = mat[0][0] - '0';
        for( int j = 1 ; j < n ; j++ ){
            p[0][j] = p[0][j-1] + mat[0][j] - '0'; 
        }
        for( int i = 1 ; i < m ; i++  ){
            p[i][0] = p[i-1][0] + mat[i][0] - '0'; 
        }
        for( int i = 1 ;i < m ; i++ ){
            for( int j = 1 ;j < n ; j++ ){
                p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + mat[i][j] - '0';
            }
        }
        // iterate through each cell
        int ans = 0;
        for( int i =0 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++){
                // consider this as the starting cell
                if( mat[i][j] == '0') continue; 

                // binary search for the max. possible side
                int l = 1, r = min(m-i, n-j);
                while(l < r) {
                    int mid = ( l + r + 1 )/2;
                    // starting index -> i, j
                    // ending index -> i + mid -1, j + mid -1 
                    int sum = p[i + mid -1][j + mid - 1] 
                            - (i?p[i-1][j + mid -1]:0) - (j?p[i + mid -1 ][j-1]:0) + ((i&&j)?p[i-1][j-1]:0);
                    if( sum < mid*mid ) r = mid -1;
                    else l = mid;
                }
                ans = max( ans, l);
            }
        }
        return ans*ans;
    }
};