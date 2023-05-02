/*
https://leetcode.com/problems/maximum-subarray/description/
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr_sum = 0;
        int ans = -1e4-1;
        for( int i = 0 ; i < n ; i++ ){
            if( curr_sum < 0 ) curr_sum = 0;
            curr_sum += nums[i];
            ans = max( ans, curr_sum);
        }
        return ans;
    }
};

// Kadane's Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr_sum = 0;
        int ans = -1e4-1;
        for( int i = 0 ; i < n ; i++ ){
            curr_sum += nums[i];
            curr_sum = max( curr_sum, nums[i]);
            ans = max( ans, curr_sum);
        }
        return ans;
    }
};