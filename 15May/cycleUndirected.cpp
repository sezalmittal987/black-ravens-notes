/*
https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs( int node, int parent, int* visited, vector<int> adj[]){
        bool ans = false;
        for( auto child : adj[node]){
            if( child == parent) continue;
            if( visited[child] == true) return true;
            else{
                visited[child]= true;
                ans |= dfs(child, node, visited, adj);
            } 
        }
        return ans;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        bool ans = false;
        int visited[n] = {};
        for( int i = 0 ;i < n ; i++ ){
            if( !visited[i]){
                visited[i] = true;
                ans |= dfs(i, -1, visited, adj);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends