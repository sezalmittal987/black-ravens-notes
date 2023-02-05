int findMaxConsecutiveOnes(vector<int>& a) {
    int n = a.size();
    int i = 0, j = 0;
    int ans = 0;
    while( j < n and i < n ){
        if( a[j] == 0 ) {
            // ans = max(ans, j -i);
            j++;
            i = j;
        }
        else{
            j++;
        }
        ans = max( ans, j - i );
    }
    // ans = max( ans, j - i);
    return ans;
}