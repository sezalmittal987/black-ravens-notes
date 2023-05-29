/*
https://leetcode.com/problems/reconstruct-itinerary/description/
*/


class Solution {
public:

    void dfs( string node, unordered_map<string, multiset<string>>& adj, vector<string>& ans){
        while(!adj[node].empty()){
            auto p = adj[node].begin();
            string child = *p;
            adj[node].erase(adj[node].find(child));
            dfs(child, adj, ans);
        }
        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // create adjacency list
        unordered_map<string, multiset<string>> adj;
        for( int i =0 ; i < tickets.size(); i++){
            adj[tickets[i][0]].insert( tickets[i][1]);
        }
        vector<string> ans;
        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

///////////// Wrong Solution because of lexical order( but for general cases)/////////////////
class Solution {
public:
    void dfs( int n, set<int>* g, vector<int>& ans ){
        while(!g[n].empty()){
            auto it = g[n].begin();
            int u = *it;
            g[n].erase(u);
            dfs(u, g, ans);
        }
        ans.push_back(n);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, int> m;
        map<int, string> um;
        for( auto u : tickets){
            m[u[0]] = 0 ;
            m[u[1]] = 0 ;
        }
        int n = 0;
        for(auto u : m){
            m[u.first] = n++;
            um.insert({m[u.first], u.first});
        }
        set<int> g[n];
        vector<int> ind(n, 0), outd(n, 0);
        for(auto e : tickets){
            g[m[e[0]]].insert(m[e[1]]);
            ind[m[e[1]]]++;
            outd[m[e[0]]]++;
        }
        int a = -1, b = -1;
        for( int i = 0 ; i < n ; i++){
            if( ind[i] - outd[i] == 1) b = i;
            if( outd[i] - ind[i] == 1) a = i;
        }
        if( a != -1 )g[b].insert(a);
        vector<int> ans, ans2;
        dfs(m["JFK"], g, ans);
        vector<string> ret;
        reverse(ans.begin(), ans.end());
        for(int i = 0 ; i < ans.size() ; i++ ){
            if( ans[i] == b and ans[i+1] == a ){
                for( int j = i + 1  ; j < ans.size() ; j++ ){
                    ans2.push_back(ans[j]);
                }
                for( int j = 1 ; j <= i ; j++ ){
                    ans2.push_back(ans[j]);
                }
                break;
            }
        }
        if( a != -1) ans = ans2;
        for(auto u :  ans) ret.push_back(um[u]);
        return ret;
    }
};