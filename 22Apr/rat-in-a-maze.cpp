/*
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/

class Solution{
    public:
    int dx[4] = {1, 0, 0,-1 };
    int dy[4] = {0, -1, 1,0 };
    char d[4] = {'D', 'L', 'R', 'U' };
    
    bool valid( int x, int y , vector<vector<int>> &m, vector<vector<int>> &v, int n){
        // out of the grid
        if( x < 0 || y < 0 || x>= n || y >=n ) return false;
        // already visited
        if( v[x][y] == 1 ) return false;
        // can't move to 0
        if( m[x][y] == 0 ) return false;
        return true;
    } 
    
    void backtrack(int row, int col, string path, vector<vector<int>> &m, int n, vector<string>& ans, vector<vector<int>>& v ){
        // base condition
        if( row == n-1 and col == n-1) {
            ans.push_back(path);
            return;
        }
        // check all the possibilities
        for( int i = 0 ; i < 4 ; i++){
            int nx = row + dx[i];
            int ny = col + dy[i];
            // validating
            if( valid(nx, ny, m, v, n)){
                v[nx][ny] = 1;
                backtrack(nx, ny, path + d[i], m, n, ans, v);
                v[nx][ny] = 0;
            }
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string path = "";
        vector<vector<int>> v(n, (vector<int>(n, 0)));
        v[0][0] = 1;
        if( m[0][0] == 1) backtrack(0, 0, path, m, n, ans, v);
        return ans;
    }
};
