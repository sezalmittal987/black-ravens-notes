#include<iostream>
using namespace std;

// int sum(int c, int d){
//     int ans = c + d;
//     return ans;
// }

int sum( int c, int d){
    int ans = c+ d;
    cout<<ans<<endl; // 8
    return ans;
}

void multiply ( int c, int d){
    c *= 2;
    d *= 2;
    cout<<c<<" "<<d<<" ";
}

int main(){
    // gives sum of two numbers;
    // a+ b
    int a, b;
    cin>>a;
    cin>>b;
    // int c = a+ b;
    // cout<<c<<endl;
    // int d = sum ( a, b);
    // cout<<d<<endl;

    // sum(a, b);
    multiply(a, b);// 6 10
    cout<<a<<" "<<b<<endl;// 3 5 
}