/*
https://practice.geeksforgeeks.org/problems/bipartite-graph/1
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs( int node, int* visited,  vector<int> *adj){
        bool ans = true;
        for( auto child : adj[node]){
            if( visited[child] == 0 ) {
                visited[child] = 3 - visited[node];
                ans &= dfs(child, visited, adj);
            }
            else if(visited[child] == visited[node]) ans = false;
        }
        return ans;
    }
    
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    int visited[n]= {};
	    bool ans = true;
	    for( int i = 0 ; i < n ; i++ ){
	        if( visited[i] == 0 ){
	            visited[i] = 1;
	            ans &= dfs(i, visited, adj);
	        }
	    }
	    return ans;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends