class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        unordered_set<int> s;
        int n = a.size();
        // adding all the elements to the set
        for( int i = 0 ; i < n ; i++ ){
            s.insert(a[i]);
        }
        int ans = 0;
        // iterate the array and find left and right boundaries of the seq. containing the element
        for( int i  = 0 ;i < n ; i++ ){
            if( s.count(a[i]) > 0){
                // check right boundary
                int x = a[i];
                while( s.count(x) == 1){
                    x++;
                }
                int r = x - 1;
                // check left boundary
                int y = a[i];
                while(s.count(y) == 1){
                    y--;
                }
                int l = y + 1;
                // take answer
                ans = max( ans, r-l + 1);
                // remove the seq. from the set
                for( int j = l; j <= r ; j++ ){
                    s.erase(j);
                }
            }
        }
        return ans;
    }
};