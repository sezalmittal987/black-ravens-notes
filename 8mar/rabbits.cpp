/*
https://leetcode.com/problems/rabbits-in-forest/description/
*/
class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int, int> m;
        int n = a.size();
        for( int i = 0 ;i < n ; i++ ){
            m[a[i] + 1]++;
        }
        int ans = n;
        for( auto u : m ){
            // a + 1 = u.first
            // b = u.second
            if( u.second%u.first != 0 ){
                // adding extras
                ans += u.first - (u.second%u.first);
            }
        }
        return ans;
    }
};