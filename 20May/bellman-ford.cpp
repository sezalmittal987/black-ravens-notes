/*
https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int s) {
        // Code here
        int dp[n];
        for( int i = 0 ; i < n ; i++){
                dp[i] = 100000000;
        }
        dp[s] = 0;
        // for each path length
        for( int k = 1; k < n ; k++){
            
            // traverse each edge
            for( auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                dp[v] = min( dp[v], dp[u] + w);
            }
        }
        bool cycle = false;
        // traverse each edge
        for( auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if( dp[u] + w < dp[v]) cycle = true;
        }
        vector<int> ans;
        if( cycle) {
            ans.push_back(-1);
            return ans;
        }
        for( int i = 0 ; i < n ; i++){
            ans.push_back(dp[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends



/*************************************************************************************************/

// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int s) {
        // Code here
        int dp[n][n];
        for( int i = 0 ; i < n ; i++){
            for ( int j = 0 ; j < n ; j++ ){
                dp[i][j] = 100000000;
            }
        }
        dp[s][0] = 0;
        // for each path length
        for( int k = 1; k < n ; k++){
            for( int v = 0 ; v < n ; v++){
                dp[v][k] = dp[v][k-1];
            }
            // traverse each edge
            for( auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                dp[v][k] = min( dp[v][k], dp[u][k-1] + w);
            }
        }
        bool cycle = false;
        // traverse each edge
        for( auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if( dp[u][n-1] + w < dp[v][n-1]) cycle = true;
        }
        vector<int> ans;
        if( cycle) {
            ans.push_back(-1);
            return ans;
        }
        for( int i = 0 ; i < n ; i++){
            ans.push_back(dp[i][n-1]);
        }
        return ans;
    }
};