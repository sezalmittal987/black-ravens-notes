#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for( int i = 0 ; i < n ; i++ ){
        cin>>arr[i];
    }
    /*
        n = 9
        arr[8], arr[7], arrr[6] ----- arr[0]
    */

    for( int i = n-1 ; i >= 0 ; i-- ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}