/*

*/

// solution-1

class Solution {
public:
    int recur( int n, vector<int>& dp ){
        if( n <= 1) return 1;
        if( dp[n]!= -1) return dp[n];
        dp[n] = 0;
        for( int i = 0 ; i <  n; i++ ){
            dp[n] += recur(i, dp)* recur( n-i-1, dp);
        }
        return dp[n];
    }
    int numTrees(int n) {
        vector<int> dp( n +1 , -1);
        return recur(n, dp);
    }
};

// solution - 2
class Solution {
public:
    int gcd(int a, int b){
        if( b == 0 ) return a;
        return gcd(b, a%b);
    }
    int recur( int n ){
        // base case
        if( n == 1) return 1;
        int a = (4*n-2);
        int b = recur(n-1);
        int c = (n + 1);
        int g = gcd( a, c);
        a/=g, c/=g;
        g = gcd( b, c);
        b/=g, c/=g;
        return a*b;
    }

    int numTrees(int n) {
        return recur(n);
    }
};