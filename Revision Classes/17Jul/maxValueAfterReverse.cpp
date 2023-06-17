class Solution {
public:
    int maxValueAfterReverse(vector<int>& a) {
        int n = a.size();
        int ans = 0 ;
        for(int i = 0 ; i < n-1 ; i++){
            ans += abs(a[i] - a[i + 1]);
        }
        int mn = 100005, mx = -100005 ;
        for( int i = 0 ; i < n-1 ; i++ ){
            mn = min( mn, max( a[i], a[i+1]));
            mx = max( mx, min(a[i], a[i+1]));
        }
        int p = ans ;
        for( int i = 0 ; i < n-1 ; i++ ){
            p = max( p, ans - abs(a[i]-a[i+1]) + abs(a[0]-a[i+1]));
        }
        for( int i = 1 ; i< n ;i++){
            p = max( p, ans - abs( a[i]-a[i-1]) +  abs(a[n-1] - a[i-1]));
        }
        ans += 2*(mx-mn);
        return max( ans, p);
    }
};