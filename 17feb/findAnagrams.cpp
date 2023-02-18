class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if( s.length() < p.length() ) return {};
        vector<int> ans;
        unordered_map<char, int> ma, mb;
        for( int i = 0 ; i < p.length() ; i++ ){
            ma[p[i]]++;
        }
        // adding the elements in the window
        int k = p.length();
        for( int i = 0 ; i < k ; i++ ){
            mb[s[i]]++;
        }
        bool flag = 1;
        for( auto u : mb){
            if( u.second != ma[u.first]){
                flag = 0;
            }
        }
        // all of the counts were equal
        if( flag == 1){
            ans.push_back(0);
        }
        for( int i = k; i<s.length() ; i++ ){
            mb[s[i-k]]--;
            mb[s[i]]++;
            bool flag = 1;
            for( auto u : mb){
                if( u.second != ma[u.first]){
                    flag = 0;
                }
            }
            // all of the counts were equal
            if( flag == 1){
                ans.push_back(i-k +1);
            }
        }
        return ans;
    }
};