class Solution {
public:
    string minWindow(string s, string t) {
        // maps store the counts of the characters
        unordered_map<char, int> ma, mb;
        for( int i = 0 ; i < t.length() ; i++ ){
            ma[t[i]]++;
        }
        int n = s.length();
        int ans = n + 1;
        string sans = "";
        // run two pointers in string s
        int i  =0 , j = 0 ;
        while( i < n and j <= n ){
            int flag = 1;
            for(auto  u : ma){
                if( u.second > mb[u.first]) flag = 0;
            }
            if( flag == 0 and j < n ) {
                if( ma.count(s[j]) == 1 ){
                    mb[s[j]]++;
                }
                j++;
            }
            else{
                if( ma.count(s[i]) == 1){
                    mb[s[i]]--;
                }
                i++;
            }
            flag = 1;
            for(auto  u : ma){
                if( u.second > mb[u.first]) flag = 0;
            }
            if( flag == 1) {
                if( ans > j - i ){
                    ans = j - i;
                    sans = s.substr(i, j-i);
                }
            }
        }
        return sans;
    }
};