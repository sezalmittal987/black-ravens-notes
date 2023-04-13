/*
https://www.interviewbit.com/problems/seats/
*/


int Solution::seats(string A) {
    int n = A.length();
    long long left[n] = {}, right[n]= {};
    long long ans; 
    long long cnt = (A[0] == '.'? 0 : 1);
    left[0] = 0;
    for( int i = 1 ; i< n; i++){
        if( A[i] == '.') left[i] = left[i-1] + cnt;
        else left[i] = left[i-1], cnt++;
    }
    right[n-1] = 0 ;
    cnt = (A[n-1] == '.'?0 :1);
    for( int i = n-2 ; i >= 0; i-- ){
        if( A[i] == '.') right[i] = right[i+1] + cnt;
        else right[i] = right[i+1], cnt++;
    }
    if( n == 1) ans = 0;
    else ans = left[0] + right[1]; 
    for( int i= 0 ; i < n-1 ; i++){
        ans = min ( ans, left[i]+ right[i+1]);
    }
    return ans%(10000003);
}
