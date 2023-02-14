class Solution {
public:
    // add it as homework
    bool checkValidity(vector<int>& a, int maxc, int days){
        
    }

    int shipWithinDays(vector<int>& a, int days) {
        int n = a.size();
        int sum = 0;
        for( int i = 0 ;i < n ; i++){
            sum += a[i];
        }
        int l = 0, r = sum; // min and max capacities possible // search space
        while(l < r) {
            int mid = (l + r)/2;
            if( checkValidity(a, mid, days) == false ) l = mid + 1;
            else r = mid; 
        }
        return l;
    }
};