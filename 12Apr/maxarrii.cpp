/*
https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1
*/

class Solution{
    public:
    int Maximize(int a[],int n)
    {
        // Complete the function
        int ans = 0;
        int mod = 1000000007;
        sort(a, a+ n);
        for( int i = 0 ; i < n ; i++ ){
            ans += ((long long)a[i]*i)%mod;
            ans%= mod;
        }
        return ans;
    }
};