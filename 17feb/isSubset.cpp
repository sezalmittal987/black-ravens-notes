string isSubset(int a1[], int a2[], int n, int mm) {
    unordered_map<int, int> m;
    for( int i = 0 ; i < n ; i++ ){
        m[a1[i]]++;
    }
    for( int i  =  0; i < mm ; i++ ){
        if( m[a2[i]] == 0 ){
            return "No";
        }
        else{
            m[a2[i]]--;
        }
    }
    return "Yes";
}