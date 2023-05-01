/*
https://leetcode.com/problems/longest-increasing-subsequence/description/
*/


/*
In solution-1, we are storing the correct index of the current number in the lis.
Whereas, in solution-2, we are storing the current number at the correct index.  
*/

// solution - 1
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int> lis(n, 1);
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < i ; j++){
                if( nums[j] < nums[i]) {
                    lis[i] = max(lis[i], lis[j]+1);
                }
            }
            ans = max( ans, lis[i]);
        }
        return ans;
    }
};

// solution - 2

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for( int i = 0 ;i < nums.size(); i++ ){
            // find position of nums[i] in lis
            // using binary search because lis is 
            // always sorted
            int l = 0, r = lis.size() - 1;
            // add at the back
            if( lis.size() == 0 or nums[i] > lis.back() ) {
                lis.push_back(nums[i]);
                continue;
            }
            while( l < r){
                int mid = (l + r)/2;
                if( lis[mid] < nums[i]) l = mid + 1;
                else r = mid;
            }
            lis[l] = nums[i];
        }
        return lis.size();
    }
};


// solution-3 , set implementation of solution-2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> lis;
        for( int i = 0 ;i < nums.size(); i++ ){
            auto it = lis.lower_bound(nums[i]);
            if( it != lis.end()){
                lis.erase(it);
            }
            lis.insert(nums[i]);
        }
        return lis.size();
    }
};