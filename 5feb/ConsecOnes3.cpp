int longestOnes(vector<int>& a, int k) {
    int n = a.size();
    int i =  0, j = 0, t = 0; 
    int ans = 0;
    // t -> current no. of flipped bits
    while( i < n  and j < n ){
        if( a[j] == 0 ){
            if( t < k ){
                t++;
                j++;
            }
            else if( t == k){
                // ans = max( ans, j - i);
                if( a[i] == 0 ) t--;
                i++;
            }
        }
        else{
            j++;
        } 
        ans = max(ans, j - i);
    }
    // ans = max( ans, j - i );
    return ans;
}