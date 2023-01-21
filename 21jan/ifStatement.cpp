#include<iostream>
using namespace std;
int main(){
    char fruit;
    char color;
    cin>>fruit;
    if( fruit == 'A' ){
        color = 'R';
    }
    if( fruit == 'B'){
        color = 'Y';
    }
    cout<<color<<endl;
}