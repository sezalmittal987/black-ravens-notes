#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i = 0;
    /* Solution 1
    while( i*i < n ){
        i++;
    }
    */
    int currentNumber = 0;
    while(currentNumber < n ){
        currentNumber += i + i + 1;
        i++;
    }
    cout<<i<<endl;
}