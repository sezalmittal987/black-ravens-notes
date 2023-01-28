#include<iostream>
using namespace std;

void func(int i){
    if( i == 0) return;
    cout<<i<<" ";
    func(i - 1);
    cout<<i<<" ";
}
int main(){
    func(5);
    cout<<endl;
}