/*
https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
*/

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        multiset<long long> s;
        long long  ans = 0;
        for( long long i = 0 ; i < n ; i++ ){
            s.insert(arr[i]);
        }
        while(s.size() > 1){
            auto it = s.begin();
            s.erase(s.begin());
            auto it2 = s.begin();
            s.erase(s.begin());
            ans += (*it) + (*it2);
            s.insert((*it) + (*it2));
        }
        return ans;
    }
};