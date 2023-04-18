/*
https://leetcode.com/problems/distant-barcodes/description/
*/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& v) {
        // find the frequencies
        map<int,int> m;
        int n = v.size();
        for( int i = 0 ; i < n ; i ++ ){
            m[v[i]]++;
        }
        priority_queue<pair<int,int>> pq; // Max Heap of {frequencies, element}
        for( auto u : m){
            pq.push({u.second, u.first});
        }
        vector<int> ans(n,0);
        int j = 0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            for( j; p.first > 0 ; j+= 2 ){
                if( j >= n ) j = 1;
                ans[j] = p.second;
                p.first--;
            }
        }
        return ans;
    }
};