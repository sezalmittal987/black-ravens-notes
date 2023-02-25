class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> a, int n){
        // Your code here
        stack<long long>s;
        vector<long long> ans;
        for( int i = n-1 ; i >= 0 ; i-- ){
            // to remove/pop the smaller numbers
            while( !s.empty() and s.top() <= a[i] ){
                s.pop();
            }
            // take answer -> top of the stack
            if(!s.empty()) ans.push_back(s.top());
            else ans.push_back(-1);
            // push current element in the stack
            s.push(a[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};