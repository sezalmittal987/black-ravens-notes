/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        multimap<int, pair<int, int>> m;
        m.insert({a[0] + b[0], {0,0}});
         set<pair<int, int>> visited;
         visited.insert({0, 0});
        vector<vector<int>> ans;
       
        while(!m.empty() and ans.size() < k){
            auto p = m.begin();
            int i = (p->second).first;
            int j = (p->second).second;
            ans.push_back({ a[i], b[j]});
            if( i +1 < a.size() and visited.count({i+1, j}) == 0 ) 
            visited.insert({i+1, j}), m.insert({a[i+1] + b[j], {i+1, j}});
            if( j + 1 < b.size()and visited.count({i, j + 1}) == 0 )
            visited.insert({i, j+1}), m.insert({a[i] + b[j+1], { i, j +1}});
            m.erase(m.begin());
        }
        return ans;
    }
};