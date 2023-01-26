#include<iostream>

using namespace std;

void sum( int arr[]){
    arr[1] = 2;
}

int main(){

    int n = 5;
    int arr[n] = {6, 7,8, 9 , 10};
    sum( arr);
    cout<<arr[1]<<endl;
}