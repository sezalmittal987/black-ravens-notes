#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for( int i = 0 ; i < n ; i++ ){
        cin>>a[i];
    }
    for( int i = 0 ;i < n ; i++ ){
        // i-1 -> 0
        int j = i -1; 
        while(j >= 0 and a[j] > a[j+1]){
            swap(a[j], a[j+1]);
            j--;
        }
    }
    for( int i = 0 ; i < n ; i++ ){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}