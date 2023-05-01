#include<iostream>

using namespace std;


void heapify( int* a, int n , int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int lar = i;
    if( l < n and a[l] > a[lar] ) lar = l;
    if( r < n and a[r] > a[lar] ) lar = r;
    swap(a[i], a[lar]);
    if( lar != i) heapify(a, n, lar);
}

void heapSort( int* a, int n){
    for( int i = n-1 ; i>= 0 ;i-- ){
        heapify( a,  n , i);
    }
    for( int i = n-1 ;i >= 0 ; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
    for( int i = 0; i< n ; i++ ){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n ; 
    cin>>n;
    int a[n];
    for( int i = 0 ; i < n ; i++) cin>>a[i];
    heapSort(a, n);
}