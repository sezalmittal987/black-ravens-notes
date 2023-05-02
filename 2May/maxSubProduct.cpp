/*
https://leetcode.com/problems/maximum-product-subarray/description/
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];
        for( int i = 1 ; i < n ; i++){
            int temp = mx;
            mx = max({mx*nums[i], mn*nums[i], nums[i]});
            mn = min({temp*nums[i], mn*nums[i], nums[i]});
            ans = max( ans, mx);
        }
        return ans;
    }
};