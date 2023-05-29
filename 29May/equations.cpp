/*
https://leetcode.com/problems/evaluate-division/description/
*/

class Solution {
public:
    double dfs(string& node, string& dest, double curr, set<string>& visited,       
        unordered_map<string, vector<pair<string, double>>> adj){
        visited.insert(node);
        if( node == dest) return curr;
        for( auto child : adj[node]){
            if( visited.count(child.first) == 0 ){
                double x = dfs(child.first, dest, curr*(child.second), visited, adj);
                if( x != -1.0) return x;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for( int i = 0 ;i < equations.size(); i++){
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], double(1)/values[i]});
        }
        vector<double> ans;
        set<string> visited;
        for(int i = 0 ; i < queries.size() ; i++ ){
            visited.clear();
            if( adj.count(queries[i][0])){
                ans.push_back(dfs(queries[i][0], queries[i][1], 1.0, visited, adj ));
            }
            else{
                ans.push_back(-1.00);
            }
        }
        return ans;
    }
};