#include<iostream>
#include<vector>
using namespace std;


void moveZeroes(vector<int>& a) {
    int i = 0;
    for( int j = 0 ; j < a.size() ;j++){
        if( a[j]> 0 ){
            a[i] = a[j];
            i++;
        }
    }
    for(i; i < a.size() ; i++){
        a[i] = 0;
    }
}

int main(){
}