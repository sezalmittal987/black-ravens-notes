int Solution::maximumGap(const vector<int> &a) {
    int n = a.size();
    if( n == 1) return 0;
    int minBucket[n-1];
    int maxBucket[n-1];
    for( int i = 0 ; i < n-1 ; i++ ) minBucket[i] = INT_MAX;
    for( int i = 0 ; i < n-1 ; i++ ) maxBucket[i] = INT_MIN;
    int mx = INT_MIN, mn = INT_MAX;
    for( int i =0 ; i < n ; i++){
        mn = min( mn, a[i]);
        mx = max( mx, a[i]);
    }
     double rangeBucket =   double(mx - mn)/ double(n-1);
    if( rangeBucket == 0 ) return 0; 
    for( int i = 0 ;i < n ; i++ ){
        int id = (a[i] - mn) / rangeBucket;
        minBucket[id] = min( minBucket[id], a[i]);
        maxBucket[id] = max(maxBucket[id], a[i]);
    }
    int ans = 0;
    int prev = maxBucket[0];
    for( int i = 1 ; i < n-1 ; i++){
        if( minBucket[i] == INT_MAX) continue;
        ans = max(ans, minBucket[i] - prev);
        prev = maxBucket[i];
    }
    ans = max( ans, mx - prev);
    return ans;
}
