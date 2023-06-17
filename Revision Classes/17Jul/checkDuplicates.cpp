class Solution {
public:
    string checkDuplicates(string& s, int len){
        unordered_map<string, int> m;
        for( int i = 0 ; i < s.length() - len + 1; i++){
            m[s.substr(i, len)]++;
        }
        for(auto u : m ){
            if( u.second > 1 ) return u.first;
        }
        return "";
    }
    string longestDupSubstring(string s) {
        int l = 0, r = s.length();
        string ans = "";
        while( l < r ){
            int mid = ( l + r + 1)/2;
            string res = checkDuplicates(s, mid);
            if( res  == "" ) r = mid - 1;
            else ans = res, l = mid;
        }
        return ans;
    }
};