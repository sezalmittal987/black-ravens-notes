/*
https://leetcode.com/problems/as-far-from-land-as-possible/description/
*/

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        // multisource BFS
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int> ( n, -1));
        for( int i = 0; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( grid[i][j] == 1){
                    // land -> source
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        if( q.size() == n*n ) return -1;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            for( int i =0 ; i < 4 ; i++){
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                if( nx >= 0 and nx < n  and ny >= 0  and ny < n and dist[nx][ny] == -1 ){
                    dist[nx][ny] = dist[p.first][p.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
        int ans = -1;
        for( int i = 0 ; i < n ; i++ ){
            for ( int j = 0 ; j < n ; j++ ){
                ans = max( ans, dist[i][j]);
            }
        }
        return ans;
    }
};