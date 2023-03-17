#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> & mat1, vector<vector<int>>& mat2){
    int n1 = mat1.size(), m1 = mat1[0].size();
    int n2 = mat2.size(), m2 = mat2[0].size();
    vector<vector<int>> ans(n1, vector<int>(m2,0) );
    for( int i = 0 ; i < n1 ;i++){ // row of mat1
        for( int j = 0 ; j < m2 ;j++){ // column of mat2
            for ( int k = 0 ; k < m1 ; k++){
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return ans;
}

// y == 0 , identity matrix
vector<vector<int>> powerMatrix( vector<vector<int>> mat, int y){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> I( m, vector<int>(m, 0));
    for( int i = 0 ; i < m ; i++ ) I[i][i] = 1;
    if( y == 0 ) return I;
    vector<vector<int>> ans;
    ans = I;
    if( y%2 == 1 ){
        ans = multiply(mat, ans);
    }
    vector<vector<int>> z = powerMatrix(mat, y/2);
    z = multiply(z, z);
    return multiply(z,ans);
}

int main(){
    int n1, m1;
    cin>>n1>>m1;
    vector<vector<int>> mat(n1, vector<int>(m1, 0) );
    // input matrices
    // mat1
    for( int i =  0 ; i< n1 ; i++){
        for ( int j = 0 ; j < m1 ; j++){
            cin>>mat[i][j];
        }
    }
    
    vector<vector<int>> ans = powerMatrix(mat, 2);
    for( int i =  0 ; i < n1 ; i++){
        for( int j = 0 ; j < m1 ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}