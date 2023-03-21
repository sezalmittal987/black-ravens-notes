class Solution {
public:
    bool isValid(string s) {
       stack<char> c;
       for( int i = 0 ; i < s.length() ; i++ ){
           // opening
           if( s[i] == '(' or s[i] == '[' or s[i] == '{'){
               // add in the stack
               c.push(s[i]);
           }
           // closing
           else{
               // check if the stack is empty or not
               if(c.empty() == true) return false;
               // stack is not empty
               if(s[i] == ')' and c.top() == '(') c.pop();
               else if( s[i] == ']' and c.top() == '[') c.pop();
               else if( s[i] == '}' and c.top() == '{') c.pop();
               else return false;
           }
       } 
       if(c.empty() == true) return true;
       return false;
    }
};

// Dynamic Programming Solution 

//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int a[505] = {};
    int sl = 0;
    bool checkPalindrome( string s, int r){
        int i = 0;
        while( i < r) {
            if( s[i] == s[r] ) {
                i++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    int palindromePartition(string s){
        int n = s.length();
        // base 
        if( n == 1) return 1;
        if( a[-n +sl] != -1 ) return a[-n+sl];
        // recurrence
        int ans = n + 1;
        for( int i = 0 ; i < n-1 ; i++ ){ // to check every partition
            int currAns = 0;
            string s1 = s.substr(i+1);
            int out = palindromePartition(s1);
            // 0 - i must be a palindrome
            int flag = checkPalindrome(s, i);
            // include answer
            if( flag == 1 ){
                currAns = 1 + out;
                ans = min(ans, currAns);
            } 
        }
        // check the edge case // no partition
        if(checkPalindrome(s, n-1)) ans = 1;
        a[-n + sl] = ans;
        return ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        sl = str.length();
        for( int i =  0 ; i < str.length() ; i++) a[i] = -1;
        return palindromePartition(str)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends