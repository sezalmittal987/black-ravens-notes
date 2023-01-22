#include<iostream>
using namespace std;

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int numberOfElements = sizeof(a)/sizeof(int);
    cout<<numberOfElements<<endl;
    // for( int i = 0 ; i < 10 ;i++ ){
    //     cin>>a[i];
    // }
    for( int i = 0 ; i <11 ; i++ ){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // cout<< a[4] + a[6] <<endl;
}