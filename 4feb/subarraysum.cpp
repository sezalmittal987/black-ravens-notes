#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n ; i ++)cin>>a[i];
    
    /* Solution 1
    for( int i =  0 ; i < n-k+1 ; i++ ){
        int sum = 0 ;
        for ( int j = i ; j <= i + k-1 ; j++){
            sum += a[j];
        }
        cout<<sum<<" ";
    }
    */

    int sum = 0;
    for( int i =0 ; i< k ; i++ ){
        sum += a[i];
    }
    cout<<sum<<" ";
    for( int i = 0 ; i < n-k ;i++){
        sum = sum - a[i] + a[i + k];
        cout<<sum<<" ";
    }
    cout<<endl;
}