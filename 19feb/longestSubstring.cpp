class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        int n = s.length();
        for( int c = 1; c<= 26 ; c++){
            // c -> max no. of unique elements in the sequence
            int i = 0, j = 0;
            unordered_map<char, int> m;
            // current number of letters having frequency >= k 
            int cnt = 0;
            while( i < n and j < n ){
                if(m.count(s[j]) or m.size() < c ){
                    m[s[j]]++;
                    if( m[s[j]] == k ) cnt++;
                    j++;
                }
                else{
                    if( m[s[i]] == k) cnt--;
                    if( m[s[i]] == 1){
                        m.erase(s[i]);
                    }
                    else {
                        m[s[i]]--;
                    }

                    i++;
                }
                int flag = 1;
                // every character has frequency greater than k
                // for( auto  u : m){
                //     if(u.second < k) flag = 0;
                // }
                if( m.size() > cnt ) flag = 0; 
                if( flag == 1 ){
                    ans = max(ans, j-i);
                }
            }
        }
        return ans;
    }
};