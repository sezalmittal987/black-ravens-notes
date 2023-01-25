#include<iostream>
using namespace std;

int main(){
    int arr[5] = {1, 2,3, 4, 5};
    cout<<arr<<endl;
    cout<<&arr[0]<<endl;
    for( int i = 1 ; i < 5 ; i ++ ){
        cout<< &(arr[i])<<endl;
    }
    cout<<*(arr + 0)<<endl; //1
    cout<<*(arr + 1)<<endl; //2
    cout<<*(arr + 2)<<endl; //3
}