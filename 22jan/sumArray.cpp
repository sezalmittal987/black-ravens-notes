#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for ( int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    /*
    sum = a[0] + a[1] + a[2] --- a[n-1]

    sum = sum + a[0]
    sum = sum + a[1]
    sum = sum + a[2]


    sum = sum + a[n-1]
    */

    int sum = 0;
    for( int i =  0 ; i < n ; i++) {
            sum += arr[i];
    }
    cout<<sum<<endl;
}