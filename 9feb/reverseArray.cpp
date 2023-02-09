#include<iostream>
#include<algorithm>
using namespace std;

int  main(){
    int arr[] = {1, 2, 3,4, 5};
    int k = 2;
    reverse(arr, arr+ 5);
    reverse(arr, arr+ k);
    reverse(arr + k, arr+ 5);
    for( int i = 0 ; i < 5 ; i++ )cout<<arr[i] <<" "; cout<<endl;
}