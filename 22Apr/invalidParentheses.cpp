/*
https://leetcode.com/problems/remove-invalid-parentheses/description/
*/

class Solution {
public:

    void backtrack( string& s, int k, int i, set<string>& ans, string path ){
        //  base condition 
        if( i == s.length() ) {
            int st = 0;
            for( int j = 0 ; j < path.length() ; j++ ){
                if( path[j] == '(') st++;
                else if( path[j] == ')'){
                    if( st > 0 ) st--;
                    else{
                        return;
                    }
                }
            }
            if( st == 0 ) ans.insert( path );
            return;
        }
        // not removing
        backtrack(s, k, i+1, ans, path + s[i] );
        // removing
        if( k > 0 and (s[i] == '(' or s[i] == ')')) backtrack(s, k-1, i+1, ans, path);
    }
    vector<string> removeInvalidParentheses(string s) {
        // min parantheses to remove
        stack<int> st;
        int n =  s.length();
        for( int i =0 ; i < n ; i++){
            if( s[i] == '(') st.push(s[i]);
            else if( s[i] == ')'){
                if( !st.empty() and st.top() == '(') st.pop();
                else st.push(s[i]);
            }
        }
        int k = st.size();
        set<string> ans;
        string path;
        backtrack(s, k, 0, ans, path);
        vector<string> result;
        for( auto u : ans){
            result.push_back(u);
        }
        return result;
    }
};