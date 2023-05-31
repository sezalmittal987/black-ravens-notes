/*
https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n, vector<int>( n, -1));
        for( int i = 0 ; i < edges.size() ;i++ ){
            cost[edges[i][0]][edges[i][1]] = edges[i][2];
            cost[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for( int i = 0 ; i < n ; i++) cost[i][i] = 0;
        for( int k = 0 ; k < n ; k++ ){
            for( int i = 0 ; i < n ; i++){
                for( int j = 0 ; j< n ; j++ ){
                    if( cost[i][k] >= 0 and cost[k][j]>=0 ) 
                        if( cost[i][j] == - 1 or cost[i][k]+ cost[k][j] < cost[i][j])
                            cost[i][j] = cost[i][k]+ cost[k][j];
                }
            }
        }
        pair<int, int>ans = { n, n};
        for( int i = 0 ;i < n  ; i++){
            int curr = 0 ;
            //count the cities reachable from ith city and distance less than threshold
            for( int j = 0;  j < n ; j++ ){
                if( cost[i][j] > 0  and cost[i][j] <= distanceThreshold ) curr++;
            }
            if( ans.first >= curr) ans = {curr, i};
        }
        return ans.second;
    }
};