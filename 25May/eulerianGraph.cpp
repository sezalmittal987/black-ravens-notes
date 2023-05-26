/*
https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int node, int* visited, vector<int>adj[]){
        visited[node] = true;
        for ( auto child : adj[node]){
            if(!visited[child]) dfs(child, visited, adj);
        }
    }
	int isEularCircuit(int n, vector<int>adj[]){
	    // Code here
	    int visited[n] = {};
	    int cc = 0;
	    for( int i = 0 ;i < n ; i++){
	        if( !visited[i] and adj[i].size()> 0){
	            cc++;
	            dfs(i, visited, adj);
	        }
	    }
	   // cout<<cc<<"# ";
	    if( cc > 1 ) return 0;
	    int oddDegrees = 0;
	    for( int i =0 ; i < n ; i++){
	        if( adj[i].size()%2 == 1) oddDegrees++;
	    }
	   // cout<<oddDegrees<<"$ ";
	    if( oddDegrees == 0) return 2;
	    else if ( oddDegrees == 2) return 1;
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends