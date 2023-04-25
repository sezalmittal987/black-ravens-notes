/*

*/


// solution 1
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // i -> current index
    // w -> current weight
    // v -> current value
    int ans = 0;
    void recur(int W, int wt[], int val[], int i, int w, int v ){
        ans = max( ans, v);
        // base condition
        if( i == -1) return;
        // cases
        // 1. consider the element
        if( w + wt[i] <= W) recur(W, wt, val, i-1, w + wt[i], v + val[i]);
        // 2. not considering
        recur( W, wt, val, i-1, w, v);
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       recur( W, wt, val, n-1, 0, 0);
       return ans;
    }
};


// solution-2 recursive DP

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.

    int recur(int W, int wt[], int val[], int n, vector<vector<int>>& dp, int i, int w ){
        // base condition
        if( i >= n ) return 0; 
        if( dp[i][w] != -1) return dp[i][w];
        dp[i][w] = 0;
        //consider ith
        if( w + wt[i] <= W ) dp[i][w] = max( dp[i][w], val[i] + recur(W, wt, val, n, dp, i + 1, w + wt[i]));
        // not consider ith
        dp[i][w]  = max( dp[i][w], recur(W, wt, val, n, dp, i+1, w));
        return dp[i][w];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp( n , vector<int>( W + 1 , -1));
       return recur( W, wt, val, n, dp, 0, 0 );
    }
};


// solution-3 iterative Dynamic Programming
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp( n , vector<int>( W + 1 , -1));
       for( int i = 0 ; i < wt[0] and i<= W   ; i++ ) dp[0][i] = 0;
       for( int i = wt[0] ; i <= W ;i++) dp[0][i] = val[0];
       for( int i = 1 ; i < n ; i++ ){
           for( int j = 0 ; j <= W ; j++ ){
               dp[i][j] = 0;
               // considering ith
               if(  j >= wt[i]) dp[i][j] = max( dp[i][j], val[i] + dp[i-1][j-wt[i]]);
               // not considering ith
               dp[i][j] = max( dp[i][j] , dp[i-1][j]);
           }
       }
       return dp[n-1][W];
    }
};