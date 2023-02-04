#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n ; i ++)cin>>a[i];
    for( int i =  0 ; i < n-k+1 ; i++ ){
        int sum = 0 ;
        for ( int j = i ; j <= i + k-1 ; j++){
            sum += a[j];
        }
        cout<<sum<<" ";
    }
}