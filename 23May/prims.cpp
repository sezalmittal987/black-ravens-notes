/*
https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        int ans = 0; // cost of MST;
        int marked[n] = {}; // n
        // visited nodes -> marked[i] = -1
        // univisited nodes( present in the set) ->marked[i] > 0
        // unvisited nodes( not in the set)-> marked[i] = 0
        multiset<pair<int, int>> s;
        int source = 0;
        s.insert({0, source});
        while(!s.empty()){ // m*log(n)
            auto p = *(s.begin());
            s.erase(s.begin());
            if( marked[p.second] == -1 ) continue;
            ans += p.first;
            marked[p.second] = -1;
            for( auto child : adj[p.second]){
                if( marked[child[0]] == -1 ) continue;
                if( marked[child[0]] == 0 ){
                    marked[child[0]] = child[1];
                    s.insert({child[1], child[0]});
                }
                else if ( marked[child[0]] <= child[1]) continue;
                else{
                    s.erase({marked[child[0]], child[0]});
                    marked[child[0]] = child[1];
                    s.insert({child[1], child[0]});
                }
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
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends


// Time Complexity -> O(n + m*logn)
// Auxiliary Space Complexity -> O(n)