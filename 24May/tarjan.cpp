#include<bits/stdc++.h>

using namespace std;

int t = 1;
void dfs( int n, int p, vector<int>* adj, int* disc, int* low, int* ap){
    disc[n] = t;
    low[n] = t;
    t++;
    int children = 0;
    for( auto child : adj[n]){
        if( child == p ) continue;
        if( disc[child] > 0 ){
            // there is a back edge
            low[n] = min( low[n], disc[child]);
        }
        else{
            children++;
            dfs(child, n, adj, disc, low, ap);

            //here, we exclude parent to exclude leaf
            if( p != -1 and disc[n] <= low[child] ) ap[n] = 1;
            low[n] = min( low[n], low[child]);
        }
    }
    if( p == -1 and children > 1) {
        ap[n] = 1;
    }
    return;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> adj[n + 1];
    int disc[n+1] = {};
    int low[n+1] = {};
    int ap[n+1] = {};
    // 1- based indexing
    for( int i =0 ; i < m ; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for( int i =1 ; i <= n ; i++ ){
        if( disc[i] == 0){
            dfs(i, -1, adj, disc, low, ap);
        }
    }
    for( int i =1 ; i <= n ; i++ ) cout<<ap[i]<<" "; 
    cout<<endl;
}


/////////////////////////////////////////////
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs( int n, int p, int& t, vector<int>* adj, int* disc, int* low, vector<int> ap){
        disc[n] = t;
        low[n] = t;
        t++;
        int children = 0;
        for( auto child : adj[n]){
            if( child == p ) continue;
            if( disc[child] > 0 ){
                // there is a back edge
                low[n] = min( low[n], disc[child]);
            }
            else{
                children++;
                dfs(child, n, t, adj, disc, low, ap);
                if( p != -1 and disc[n] <= low[child] ) ap.push_back(n);
                low[n] = min( low[n], low[child]);
            }
        }
        if( p == -1 and children > 1) {
            ap.push_back(n);
        }
        return;
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        int t = 1;
        int disc[n] = {};
        int low[n] = {};
        vector<int> ap;
        // 0- based indexing
        for( int i = 0 ; i < n ; i++ ){
            if( disc[i] == 0){
                dfs(i, -1, t, adj, disc, low, ap);
            }
        }
        return ap;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends