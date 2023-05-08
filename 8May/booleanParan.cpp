/*
https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int recur(int i, int j, string& s, bool k, int dp[200][200][2]){
        // base cases
        if( i == j){
            if( s[i] == 'T' and k == true) return 1;
            if ( s[i] == 'F' and k == false) return 1;
            else return 0;
        }
        // recurrence relation
        if( dp[i][j][k] != - 1) return dp[i][j][k];
        dp[i][j][k] = 0;
        for ( int k1 = i + 1; k1 < j; k1+= 2){
            int c1 = recur(i, k1-1, s, true, dp)*recur(k1+1, j, s,true, dp); // TT
            int c2 = recur(i, k1-1, s, true, dp)*recur(k1+1, j, s,false, dp); // TF
            int c3 = recur(i, k1-1, s, false, dp)*recur(k1+1, j, s,true, dp); // FT
            int c4 = recur(i, k1-1, s, false, dp)*recur(k1+1, j, s,false, dp); // FF
            if( s[k1] == '&'){
                if(k) dp[i][j][k] += c1%1003;
                else dp[i][j][k] += c2%1003 + c3%1003 + c4%1003;
            }
            else if ( s[k1] == '|'){
                if( k) dp[i][j][k] += c1%1003 + c2%1003 + c3%1003;
                else dp[i][j][k] += c4%1003;
            }
            else if( s[k1] == '^'){
                if( k ) dp[i][j][k] += c2%1003+ c3%1003;
                else dp[i][j][k] += c1%1003+ c4%1003;
            }
        }
        dp[i][j][k] %= 1003;
        return dp[i][j][k];
    }
    
    int countWays(int N, string S){
        // code here
        int dp[200][200][2];
        for( int i = 0 ; i < N; i++){
            for( int j = 0; j < N ; j++ ){
                for( int k = 0 ; k< 2 ; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return recur(0, N-1, S, true, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends