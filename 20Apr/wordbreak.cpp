/*
https://leetcode.com/problems/word-break/description/
*/

class Solution {
public:
    bool backtrack( string s, vector<string>& wordDict){
        // base condition
        if( s.empty()) return true;
        // check all the possibilities
        for( int i = 1; i <= s.length(); i++){
            // validating -> check in the dictionary
            bool valid = false;
            for( int j = 0 ; j < wordDict.size() ; j++){
                if( s.substr(0, i) == wordDict[j]) valid = true;
            }
            if(valid and backtrack(s.substr(i), wordDict)) return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return backtrack(s, wordDict);
    }
};