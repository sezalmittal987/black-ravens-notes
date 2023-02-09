#include<iostream>
#include<algorithm>
using namespace std;

int  main(){
    int n;
    cin>>n;
    int a[n];
    for( int i = 0 ; i < n ; i++ ){
        cin>>a[i];
    }
    for( int i = 0 ; i < n; i++ ){
        int min_index = i ;
        for( int j = i ; j < n ; j++ ){
            if( a[min_index] > a[j] ){
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }
    for( int i = 0 ; i < n ; i++ ){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}