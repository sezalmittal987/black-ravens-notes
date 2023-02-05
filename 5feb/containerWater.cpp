int maxArea(vector<int>& a) {
    int n = a.size();
    int ans = 0;
    for( int i = 0 ; i < n ; i++ ){
        for ( int j = i + 1; j < n ;j++ ){
            int curr = min(a[i], a[j]) * (j -i );
            ans = max( ans, curr);
        }
    }
    return ans;
}

int maxArea(vector<int>& a) {
    int n = a.size();
    int ans = 0;
    int i = 0 , j = n-1;
    while( i < j ){
        int curr = min(a[i], a[j])*(j-i);
        ans = max( ans, curr);
        if( a[i] < a[j]) i++;
        else j--;
    }
    return ans;
}