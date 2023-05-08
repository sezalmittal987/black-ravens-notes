/*

https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int recur(int i, int j, int* arr, int dp[100][100]){
        // base case
        if( i == j ) return 0;
        // recurrence relation
        if( dp[i][j] != -1) return dp[i][j];
        dp[i][j] = INT_MAX;
        for( int k = i ;k < j ; k++){
            dp[i][j] = min( dp[i][j], recur( i,k, arr, dp) + recur(k+1, j, arr, dp) + arr[i-1]*arr[k]* arr[j]);
        }
        return dp[i][j];
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int dp[100][100];
        for( int i = 0 ; i < N ; i++){
            for( int j = 0 ; j < N ; j++){
                dp[i][j] = -1;
            }
        }
        return recur(1, N-1, arr, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends