class Solution {
public:
        int longestWPI(vector<int>& hours) {
        int res = 0, prefix_sum = 0, n = hours.size();
        unordered_map<int, int> seen;
        for (int i = 0; i < n; ++i) {
            prefix_sum += hours[i] > 8 ? 1 : -1;
            // if prefix sum is positive
            // consider whole prefix array
            if (prefix_sum > 0) {
                res = i + 1;
            } 
            // if negative, then answer will be first occurence of
            // prefix_sum -1.
            else {
                if (seen.find(prefix_sum) == seen.end())
                    seen[prefix_sum] = i;
                if (seen.find(prefix_sum - 1) != seen.end())
                    res = max(res, i - seen[prefix_sum - 1]);
            }
        }
        return res;
    }
};