class Solution {
public:
    bool isAlienSorted(vector<string>& v, string s) {
        unordered_map<char, int> idx;
        int n = v.size();
        // store all the indexes
        for( int i = 0 ; i < s.length(); i++ ){
            idx[s[i]] = i;
        }
        for( int i = 0 ;i < n-1 ; i++) {
            int j = 0;
            while(j < v[i].length() and j < v[i+1].length() and v[i][j] == v[i+1][j] ) j++;
            // equal strings
            if( j == v[i].length() and j == v[i+1].length()) {
                // do nothing
            }
            else if( j == v[i].length()){
                // do nothing
            } 
            else if( j == v[i+1].length()){
                // (i + 1)th string is completed and ith string has some ccharacters left
                return false;
            }
            else{
                // in which both strings have characters left
                if (idx[v[i][j]] > idx[v[i+1][j]]) return false;
            }
        }
        return true;
    }
};