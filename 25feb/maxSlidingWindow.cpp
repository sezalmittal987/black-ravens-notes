class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<pair<int, int>> q;
        int n = a.size();
        vector<int> ans;
        for( int i = 0 ; i < k ; i++ ){
            while(!q.empty() and q.back().first <= a[i] ){
                q.pop_back();
            }
            q.push_back({a[i],i});
        }
        ans.push_back(q.front().first);
        for( int i = k ; i < n ; i++ ){
            // removing element from the window
            if( !q.empty() and q.front().second == i - k ) q.pop_front();
            // add element to the window
            while(!q.empty() and q.back().first <= a[i] ){
                q.pop_back();
            }
            q.push_back({a[i],i});
            // add to the answer
            ans.push_back(q.front().first);
        }
        return ans;
    }
};