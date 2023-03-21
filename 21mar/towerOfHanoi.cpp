#include<iostream>
using namespace std;

void recur(int n, char from, char to, char helping){
    // base
    if( n == 1) {
        cout<<"Transfer the disc from "<<from<<" to "<<to<<endl;
        return;
    }
    // recursion
    recur(n-1, from, helping, to);
    recur(1, from, to , helping);
    recur(n-1, helping, to, from);
}
int main(){
    int n ;
    cin>>n;
    recur(n, 'A', 'C', 'B');
}