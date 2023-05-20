/*
https://leetcode.com/problems/shortest-path-with-alternating-colors/description/
*/

class Solution {
public:

    vector<int> shortestAlternatingPaths( int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> adj[2][n]; // adj[0] is for all red edges, adj[1] is for all blue edges
        for( int i = 0 ;i < redEdges.size() ; i++ ){
            adj[0][redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for( int i = 0 ;i < blueEdges.size() ; i++ ){
            adj[1][blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        int dist[2][n];
        for( int i =0 ; i < 2 ; i++){
            for( int j = 0 ; j< n ; j++) {
                dist[i][j] = -1;
            }
        }
        // BFS
        queue<pair<int, int>> q; //{ node, color of incident edge}
        q.push({0, 0}); // incident to 0 was red edge
        q.push({0, 1}); // inciden to 0 was blue edge
        dist[0][0] = 0;
        dist[1][0] = 0;
        while(!q.empty()){
            auto  p = q.front();
            q.pop();
            int node = p.first;
            int color = p.second;
            // traverse all the children
            for( auto child : adj[1-color][node]){
                if( dist[1-color][child] > -1 ) continue;
                dist[1-color][child] = dist[color][node] + 1;
                q.push({child, 1-color}); 
            }
        }
        vector<int> ans( n);
        for( int i = 0 ; i < n ; i++){
            if( dist[0][i] == -1 ) ans[i] = dist[1][i];
            else if( dist[1][i] == -1) ans[i] = dist[0][i];
            else ans[i] = min( dist[0][i], dist[1][i]);
        }
        return ans;
    }
};