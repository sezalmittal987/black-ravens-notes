/*
https://leetcode.com/problems/n-queens/description/
*/

class Solution {
public:

    void backtrack(int n,vector<vector<string>>& ans, vector<string>& curr ){
        // base condition
        if( curr.size() == n ) {
            ans.push_back(curr);
            return;
        }
        //check all the possibilities
        string element;
        for( int i = 0 ;i < n ;i++) element.push_back('.');
        for( int i = 0 ; i < n ; i++ ){ // i-> current colum where you are adding the queen
            // validate
            bool valid = true;
            // validate column
            for( int j = 0 ;j < curr.size() ; j++){
                if( curr[j][i] == 'Q') valid = false;
            }
            int row = curr.size();
            int col = i;
            // validate first diagonal
            int k = 1;
            while( row-k >=0 and col-k>= 0 ){
                if( curr[row-k][col-k] == 'Q') valid = false;
                k++;
            }
            // validate second diagonal
            k = 1;
            while( row-k >= 0 and  col+k < n ){
                if( curr[row-k][col+k] == 'Q') valid = false;
                k++;
            }

            if( valid){
                element[i] = 'Q';
                curr.push_back(element);
                backtrack(n, ans, curr);
                curr.pop_back();
                element[i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(n, ans, curr);
        return ans;
    }
};