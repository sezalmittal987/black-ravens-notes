#include<iostream>
using namespace std;
int main(){
    // if number is positive then print "P"
    // negative, "N"
    // 0, "Z"
    int num;
    cin>>num;
    if( num == 0 ){
        cout<<"Z";
    }
    else{
        if( num > 0 ){
            cout<<"P";
        }
        else{
            cout<<"N";
        }
    }
}