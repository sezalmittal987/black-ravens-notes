#include<iostream>
#include<vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<vector<int>> v(rowIndex+1);
    v[0].push_back(1);//[0]=1;
    if( rowIndex == 0) return v[0];
    v[1].push_back(1);
    v[1].push_back(1);
    for(int i=2;i<=rowIndex;i++){
        v[i].push_back(1);
        for(int j=1;j<i;j++){
            v[i].push_back(v[i-1][j-1]+v[i-1][j]);
        }
        v[i].push_back(1);
    }
    return v[rowIndex];
}

int main(){

}