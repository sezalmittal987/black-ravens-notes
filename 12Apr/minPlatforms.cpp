/*
https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
*/

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	// timestamp, nature(start/end)
    	vector<pair<int, int>> v;
    	for( int i= 0 ;i < n; i++){
    	    v.push_back({arr[i], -1});
    	    v.push_back({dep[i], 1});
    	}
    	sort(v.begin(), v.end());
    	int ans = 0;
    	int cnt = 0;
    	for( int i = 0 ; i < 2*n ; i++ ){
    	    cnt -= v[i].second;
    	    ans = max( ans, cnt);
    	}
    	return ans;
    }
};