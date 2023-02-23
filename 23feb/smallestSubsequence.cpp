class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> t;
        unordered_map<char, int> m;
        string ans;
        // store the last occurences
        for( int i = 0 ; i < s.length() ; i++ ){
            m[s[i]] = i ;
        }
        set<int> visit;
        for( int i = 0 ; i < s.length() ; i++ ){
            // popping out the larger letters if they are occuring after current idx.
            // push the current element to the stack
            if(visit.count(s[i]) == 0){
                while( !t.empty() and t.top() >= s[i] and m[t.top()] >= i ){
                    visit.erase(t.top());
                    t.pop();
                }
                t.push(s[i]);
                visit.insert(s[i]);
            } 
        }
        while(!t.empty()){
            ans.push_back(t.top());
            cout<<t.top()<<" ";
            t.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};