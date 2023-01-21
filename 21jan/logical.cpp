#include<iostream>

using namespace std;

int main(){
    int a = -5;
    int b = 0;
    cout<<(a&&b)<<endl;
    cout<<(b&&a)<<endl;
    cout<<(a||b)<<endl;
    cout<<(!a)<<endl;
    cout<<(!b)<<endl;

    cout<<(a!=b)<<endl; 
    // 1, 1 -> 0
    // 1, 0 -> 1
    // 0, 1-> 1
    // 0, 0 -> 0
}