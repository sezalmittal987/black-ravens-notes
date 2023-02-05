void recur(vector<int>& ans, vector<vector<int>>& m, int a, int b, int c, int d){
    // base condition
    if ( a > c or b> d ) return;
    // pattern
    for( int j = b ; j<= d ; j++){
        ans.push_back(m[a][j]);
    }
    for( int i = a + 1 ;i <= c ;i++ ){
        ans.push_back(m[i][d]);
    }
    if( c != a ){
        for( int j = d-1 ; j>= b ; j--){
            ans.push_back(m[c][j]);
        }
    }
    if( d!= b){
        for( int i = c - 1 ;i >= a + 1 ;i-- ){
            ans.push_back(m[i][b]);
        }
    }
    recur(ans, m, a+1, b+1, c-1, d-1);
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size();
    int n = matrix[0].size();
    recur( ans, matrix, 0,0, m-1 , n-1);
    return ans;
}