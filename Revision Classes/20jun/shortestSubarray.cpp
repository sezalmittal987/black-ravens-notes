class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size();
        // prefix sum array
        long long p[n];
        p[0] = a[0];
        for( int i = 1 ; i < n ; i++ ){
            p[i] = p[i-1] + a[i];
        }
        int ans = 1000000;
        deque<pair<long long, int>> q;
        q.push_back({0, -1});
        for( int j = 0; j < n ; j++ ){
            long long t = p[j] - k;
            while(!q.empty() and q.front().first <= t ) {
                ans = min( ans, j - q.front().second);
                q.pop_front();
            }
            while(!q.empty() and q.back().first >= p[j]) q.pop_back();
            q.push_back({p[j], j});
        }
        if( ans == 1000000) return -1;
        return ans;
    }
};