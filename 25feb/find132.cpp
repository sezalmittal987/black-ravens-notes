class Solution {
public:
    bool find132pattern(vector<int>& a) {
        int n = a.size();
        stack<int> s;
        int maxPossk = -1e9;
        bool poss = false; // whether there is any possible value of k or not.
        for( int i = n-1 ;i>= 0 ; i-- ){
            if( poss == true and a[i] < maxPossk) {
                return true;
            }
            while(s.empty() == false and s.top() < a[i]){
                // taking the value to be popped as a possible k
                maxPossk = max( maxPossk, s.top());
                poss = true;
                s.pop();
            }
            s.push(a[i]);
        }
        return false;
    }
};