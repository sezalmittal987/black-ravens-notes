#include<iostream>
using namespace std;

int main(){

    int a = 5;
    int& i = a;
    cout<<i<<endl; // 5
    i *= 2;
    cout<<a<<endl; // 10
    cout<<&a<<endl;
    cout<<&i<<endl;
    int b = 5;
    i = b;
    cout<<i<<" "<<a<<" "<<b<<" ";
    // &i = b;  // we cannot reassign the reference variables.
}
