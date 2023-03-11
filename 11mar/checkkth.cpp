#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    if(( n & ( 1<<k )) == 0 ){
        cout<<"False"<<endl;
    }
    else{
        cout<<"True"<<endl;
    }
}