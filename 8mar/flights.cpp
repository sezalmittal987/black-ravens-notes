/*
https://leetcode.com/problems/corporate-flight-bookings/description/
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& a, int n) {
        vector<int> ex(n + 2, 0);
        int m = a.size();
        for ( int i  = 0 ; i < m ; i++ ){
            int l = a[i][0];
            int r = a[i][1];
            int x = a[i][2];
            ex[l] += x;
            ex[r + 1] -= x;
        }
        vector<int> ans;
        for( int i = 1 ;i <= n ; i++ ){
            // calculating prefix sum values
            ex[i] += ex[i-1];
            // adding the values to the answer
            ans.push_back( ex[i]);
        }
        return ans;
    }
};