#include<iostream>
using namespace std;

int main(){
    int a;
    cin>>a;
    switch(a){
        case 1:
        cout<<"Apple"<<endl;
        case 2:
        cout<<"Banana"<<endl;
        case 3:
        cout<<"Cherry"<<endl;
        default:
        cout<<"Oranges"<<endl;
    }
}