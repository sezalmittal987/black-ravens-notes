#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin>>a;
    cin>>b;
    (a>=b)?cout<<a:cout<<b;

    int maxNumber = (a>=b)?a:b;
    cout<<maxNumber;
}