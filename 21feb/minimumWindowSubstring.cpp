class Solution {
public:
    string minWindow(string s, string t) {
        // maps store the counts of the characters
        unordered_map<char, int> ma, mb;
        for( int i = 0 ; i < t.length() ; i++ ){
            ma[t[i]]++;
        }
        int n = s.length();
        int m = t.length();
        int ans = n + 1;
        pair<int, int> sans;
        // run two pointers in string s
        int i  =0 , j = 0 ;
        int cnt = 0;
        while( i < n and j <= n ){
            // if we can add more elements to the window or not
            // characters you have chosen must be less than m
            if( cnt < m and j < n ) {
                if( ma.count(s[j]) == 1 ){
                    mb[s[j]]++;
                    if(mb[s[j]] <= ma[s[j]]) cnt++;
                }
                j++;
            }
            else{
                if( ma.count(s[i]) == 1){
                    if(mb[s[i]] <= ma[s[i]]) cnt--;
                    mb[s[i]]--;
                }
                i++;
            }
            if( cnt == m) {
                if( ans > j - i ){
                    ans = j - i;
                    sans ={i, j};
                }
            }
        }
        if( ans == n + 1) return "";
        return s.substr(sans.first, sans.second - sans.first);
    }
};