class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0; 
        int j = 0;
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>> ans;
        while(i < n and j < m ){
            //overlapping
            if( secondList[j][1] >= firstList[i][0] and secondList[j][0] <= firstList[i][1]){
                int l = max(firstList[i][0], secondList[j][0]);
                int r = min(firstList[i][1], secondList[j][1]);
                // vector<int> curr;
                // curr.push_back(l);
                // curr.push_back(r);
                // ans.push_back(curr);

                ans.push_back({l, r});
            }
            if( secondList[j][1]  > firstList[i][1]) i++;
            else j++;
        }
        return ans;
    }
};