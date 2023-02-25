class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        // next smaller and previous smaller
        stack<pair<int, int>> s;
        int n = a.size();
        // find next smaller bar
        pair<int, int>  right[n]; // right boundary
        for( int i = n-1 ;i >= 0 ; i-- ){
            while(s.empty() == false and s.top().first >= a[i] ){
                s.pop();
            }
            if(s.empty()) right[i] = {-1, n};
            else right[i] = s.top();
            s.push({a[i], i});
        }
        // find previous smaller bar
        while(!s.empty()) s.pop();
        pair<int, int> left[n]; // left boundary
        for( int i = 0 ; i < n ; i++ ){
            while(s.empty() == false and s.top().first >= a[i] ){
                s.pop();
            }
            if(s.empty()) left[i] = {-1, -1};
            else left[i] = s.top();
            s.push({a[i], i});
        }

        // consider ith bar as the smallest bar and find the ans
        int ans = 0;
        for( int i = 0 ; i< n ; i++ ){
            ans = max(ans, (right[i].second - left[i].second - 1)*a[i]);
        }
        return ans;
    }
};