#include<iostream>
using namespace std;

int main(){
    int n1, m1, n2, m2;
    cin>>n1>>m1>>n2>>m2;
    int mat1[n1][m1], mat2[n2][m2];
    // input matrices
    // mat1
    for( int i =  0 ; i< n1 ; i++){
        for ( int j = 0 ; j < m1 ; j++){
            cin>>mat1[i][j];
        }
    }
    // mat2
    for( int i =  0 ; i< n2 ; i++){
        for ( int j = 0 ; j < m2 ; j++){
            cin>>mat2[i][j];
        }
    }
    if( m1 != n2 ){
        cout<<-1<<endl;
        return 0 ;
    }
    int ans[n1][m2] = {};
    for( int i = 0 ; i < n1 ;i++){ // row of mat1
        for( int j = 0 ; j < m2 ;j++){ // column of mat2
            for ( int k = 0 ; k < m1 ; k++){
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    for( int i =  0 ; i < n1 ; i++){
        for( int j = 0 ; j < m2 ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}