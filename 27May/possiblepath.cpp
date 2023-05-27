/*
https://practice.geeksforgeeks.org/problems/possible-paths3834/1
*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    // Code here
	    int n = graph.size();
	    int dp[n][k+1]= {};
	    for( int i = 0 ;i < n ; i++){
	        dp[i][1] = graph[u][i];
	    }
	    for( int l = 2; l <= k ; l++){
	        for( int i = 0 ; i < n ; i++){
	            for( int j = 0 ; j < n ; j++){
	                // there is an edge from j to i
	                if( graph[j][i]){
	                    dp[i][l] += dp[j][l-1];
	                    dp[i][l] %= 1000000007;
	                }
	            }
	        }
	    }
	    return dp[v][k];
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>graph(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		int u, v, k;
		cin >> u >> v >> k;
		Solution obj;
		int ans = obj.MinimumWalk(graph, u, v, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends