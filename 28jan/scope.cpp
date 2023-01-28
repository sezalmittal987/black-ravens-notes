#include<iostream>
using namespace std;

int b = 10; // global variable

int main(){
    int a = 5;//local variable
    if(true){
        int a = 6; //local variable
        cout<<a<<endl;

    }
    cout<<a<<endl;
}