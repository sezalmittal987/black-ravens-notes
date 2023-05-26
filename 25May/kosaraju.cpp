/*
https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs1(int n, vector<vector<int>>& adj, int* visited, stack<int> & dfsTree){
	    visited[n] = 1;
	    for( auto child : adj[n]){
	        if( !visited[child] ){
	            dfs1(child, adj, visited, dfsTree);
	        }
	    }
	    dfsTree.push(n);
	}
	
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        //code here
        int visited[n] = {};
        stack<int> dfsTree;
        for( int i = 0 ;i < n ; i++ ){
            if( !visited[i]) {
                dfs1(i, adj, visited, dfsTree);
            }
        }
        // reverse all the edges
        vector<vector<int>> adj2(n);
        for( int i=  0 ;i < n ; i++){
            for( int j = 0 ; j < adj[i].size() ; j++){
                adj2[adj[i][j]].push_back(i);
            }
        }
        for( int i = 0; i < n ; i++ ) visited[i] = 0;
        int ans = 0;
        stack<int> s;
        while(!dfsTree.empty()){
            auto i = dfsTree.top();
            dfsTree.pop();
            if( !visited[i]){
                ans++;
                dfs1(i,adj2, visited, s);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends