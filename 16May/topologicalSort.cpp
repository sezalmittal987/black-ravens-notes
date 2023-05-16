/*
https://practice.geeksforgeeks.org/problems/topological-sort/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs( int node, int* visited, int* recursiveStack, vector<int> adj[]){
        recursiveStack[node] = true;
        bool ans = false;
        for( auto child : adj[node]){
            if( visited[child] == true) {
                // either from the same path 
                if (recursiveStack[child] == true) return true;
                // or different path
            }
            else{
                visited[child]= true;
                ans |= dfs(child, visited, recursiveStack, adj);
            } 
        }
        recursiveStack[node] = false;
        return ans;
    }
    // Function to detect cycle in an undirected graph.
    bool isCyclic(int n, vector<int> adj[]) {
        // Code here
        bool ans = false;
        int recursiveStack[n] = {};
        int visited[n] = {};
        for( int i = 0 ;i < n ; i++ ){
            if( !visited[i]){
                visited[i] = true;
                ans |= dfs(i,  visited, recursiveStack, adj);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends