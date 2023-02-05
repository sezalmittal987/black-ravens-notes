vector<int> twoSum(vector<int>& a, int k) {
    int n = a.size();
    for( int i = 0 ; i < n ; i++ ){
        for( int j = i + 1; j < n ; j++ ){
            if( a[i] + a[j] == k){
                vector<int> ans;
                ans.push_back(i +1);
                ans.push_back(j + 1);
                return ans;
            }
        }
    }
    // vector<int> ans;
    // return ans;
    return ans;
}

// Solution 2
vector<int> twoSum(vector<int>& a, int k) {
    int n = a.size();
    int i = 0;
    int j = n-1;
    while( i < j ){
        if( a[i] + a[j] < k ){
            i++;
        }
        else if( a[i] + a[j] > k){
            j--;
        }
        else{
            vector<int> ans;
            ans.push_back(i + 1);
            ans.push_back(j + 1);
            return ans;
        }
    }
    return {};
}