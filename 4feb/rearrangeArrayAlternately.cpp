#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++ ){
        cin>>a[i];
    }
    // n is even
    int p1 = 0, p2 = n-1;
    while(p1 < p2 ){
        cout<<a[p2] <<" "<<a[p1]<<" ";
        p1++; p2--;
    }
    cout<<endl;
}