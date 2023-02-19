class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if( n < k ) return false;
        unordered_set<string> st;
        // insert first k elements into the window
        string curr = "";
        for( int i  = 0  ;i < k ; i++ ){
            curr.push_back(s[i]);
        }   
        st.insert(curr);
        //slide the window
        for(int i = k ; i < n ; i++ ){
            curr.erase(0, 1);
            curr.push_back(s[i]);
            st.insert(curr);
        }
        if( st.size() == pow(2, k)) return true;
        return false;
    }
};


class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if( n < k ) return false;
        unordered_set<int> st;
        // insert first k elements into the window
        int num = 0;
        for( int i  = 0  ;i < k ; i++ ){
            num = num*2 + (s[i]- '0');
        }   
        st.insert(num);
        //slide the window
        for(int i = k ; i < n ; i++ ){
            num = num%(int(pow(2, k-1)));
            num = num*2 + (s[i]- '0');
            st.insert(num);
        }
        if( st.size() == pow(2, k)) return true;
        return false;
    }
};