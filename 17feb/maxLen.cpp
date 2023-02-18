class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        unordered_map<int, int> m;
        int p = 0;
        int ans = 0;
        m.insert({0, -1});
        for( int i =  0 ; i < n ; i++ ){
            p += a[i];
            // present
            if( m.count(p) == 1) {
                // take answer
                ans = max( ans, i - m[p]);
            }
            // absent
            else{
                m.insert({p, i});
            }
        }
        return ans;
    }
};