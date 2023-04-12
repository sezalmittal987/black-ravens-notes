/*
https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1
*/

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    static bool compare(pair<int, int> a, pair<int, int> b){
        if( a.second < b.second) return true;
        else if ( a.second > b.second ) return false;
        return a.first > b.first; 
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> v;
        for( int i = 0 ; i < n ;i++){
            v.push_back({start[i], end[i]});
        }
        sort(v.begin(), v.end(), compare);
        int last = 0;
        int ans = 0;
        for( int i = 0; i <n ; i++ ){
            if( last < v[i].first) {
                // count current interval
                ans++;
                last = v[i].second;
            }
        }
        return ans;
    }
};