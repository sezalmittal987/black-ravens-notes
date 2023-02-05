int MissingNumber(vector<int>& a, int n) {
    // Your code goes here
    int sum = 0;
    for( int i = 1; i <= n ; i++ ){
        sum += i;
    }
    for( int i = 0 ;i < n-1 ; i++ ){
        sum -= a[i];
    }
    return sum;
}

//Solution 2

int MissingNumber2(vector<int>& a, int n) {
    // Your code goes here
    int sum = 0;
    for( int i = 1; i <= n ; i++ ){
        sum ^= i;
    }
    for( int i = 0 ;i < n-1 ; i++ ){
        sum ^= a[i];
    }
    return sum;
}