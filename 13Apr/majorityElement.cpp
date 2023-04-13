/*
https://leetcode.com/problems/majority-element/description/
*/

// Boyer-Moore

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int k = -1;
        int c = 0;
        for( int i = 0 ; i < nums.size() ; i++ ){
            if( c == 0 ) k = nums[i];
            if( nums[i] == k ) c++;
            else c--;
        }
        // check if the candidate is right
        c = 0 ;
        for (int i = 0 ; i < nums.size() ;i++ ){
            if( nums[i] == k) c++;
            else c--;
        }
        if( c> 0 ) return k;
        return -1;
    }
};