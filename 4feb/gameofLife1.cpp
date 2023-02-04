#include<iostream>
#include<vector>
using namespace std;

//using function to check the validity of indexes.
bool valid( int x, int y, int m, int n ){
    if( x >= 0 && x < m && y >=0 && y < n) return true;
    return false;
}

void gameOfLife(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> dx = {0, 0, -1, 1, -1, -1, 1, 1};
    vector<int> dy = {-1, 1, 0, 0, -1, 1, -1, 1};
    // vector< vector<int>> mat2(m, (vector<int>(n)));
    for( int i = 0 ;i < m ; i++ ){
        for( int j = 0 ; j< n ; j++ ){
            int cnt = 0;
            for( int k = 0 ; k < 8 ; k++ ){
                if( valid(i + dx[k], j + dy[k], m, n) && mat[i + dx[k]][j+dy[k]]%2 == 1) cnt++;
            }
            if( mat[i][j] == 0 ){ //dead
                if(cnt == 3) mat[i][j] = 2; // (10)2 -> (2)10
                else mat[i][j] = 0; // (00)2 -> (0)10
            }
            else{ // alive
                if( cnt < 2 or cnt > 3 ) mat[i][j] = 1; //(01)2 = (1)10
                else mat[i][j] = 3; // (11)2 = (3)10
            }
        }
    }
    for( int i = 0 ;i < m ; i++ ){
        for( int j = 0 ; j< n ; j++ ){
            mat[i][j] >>= 1; //mat[i][j] /= 2
        }
    }
}

int main(){
    
}