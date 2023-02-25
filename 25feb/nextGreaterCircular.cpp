class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        stack<int> s;
        vector<int> ans(n , -1);
        for( int i = 2*n-1 ; i >= 0 ; i-- ){
            while(!s.empty() and s.top() <= a[i%n] ){
                s.pop();
            }
            if(!s.empty()){
                ans[i%n] = s.top();
            }
            s.push(a[i%n]);
        }
        return ans;
    }
};