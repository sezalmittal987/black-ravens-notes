/*
https://leetcode.com/problems/sudoku-solver/description/
*/

class Solution {
public:

    bool valid(vector<vector<char>>& board , int row, int col, char x){
        // validate row
        for( int i = 0 ; i < 9 ; i++ ){
            if(board[row][i] == x) return false;
        }
        // validate col
        for( int i = 0 ; i< 9 ; i++ ){
            if( board[i][col] == x) return false;
        }
        // validate the block
        int sr = 3*(row/3);
        int sc = 3*(col/3);
        for( int i = 0 ; i < 3 ; i++ ){
            for ( int j = 0 ; j < 3 ; j++){
                if( board[sr+i][sc+j] ==  x)  return false;
            }
        }
        return true;
    }
    // true-> answer found, false->answer not found
    bool backtrack(vector<vector<char>>& board ){
        // find the vacant cell
        for( int i = 0 ;i < 9 ; i++){
            for( int j = 0 ; j < 9 ; j++){
                if( board[i][j] == '.'){
                    // check all the possibilities
                    for( char k = '1' ; k <= '9' ;k++){
                        // validate
                        if( valid(board, i, j, k)){
                            board[i][j] = k;
                            if(backtrack(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    // no solution from this branch
                    return false;
                }
            }
        }
        // base condition -> no vacancies
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};