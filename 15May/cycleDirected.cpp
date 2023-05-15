/*
https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/

bool dfs( int node, int* visited, int* recursiveStack, vector<int> adj[]){
        recursiveStack[node] = true;
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
        int recursiveStack[n] = {};
        int visited[n] = {};
        for( int i = 0 ;i < n ; i++ ){
            if( !visited[i]){
                visited[i] = true;
                ans |= dfs(i, -1, visited, recursiveStack, adj);
            }
        }
        return ans;
    }