#include<iostream>
#include<vector>

using namespace std;

int findPivot(int* a, int l , int r){
    while( l < r ){
        int mid = ( l + r)/2;
        if( a[mid] >= a[0] ) l = mid + 1;
        else r = mid;
    }
    if( a[l] >= a[0] ) return 0;
    return l;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for( int i = 0 ;i < n ; i++) cin>>a[i];
    cout<<findPivot(a, 0, n-1)<<endl;
}