#include<iostream>
#include<vector>

using namespace std;
 
int binarySearch2( int *a , int l, int r, int target){
    // base condition
    // if(  l > r ) return -1;
    if( l == r ) return l;
    int mid = ( l + r)/2; 
    if( a[mid] > target ) r = mid -1 ;
    else l = mid; 
    return binarySearch(a, l, r, target);
}

int binarySearch( int *a , int l, int r, int target){
    // base condition
    if(  l > r ) return -1;
    int mid = ( l + r)/2; 
    if( a[mid] > target ) r = mid -1 ;
    else if( a[mid] < target ) l = mid + 1;
    else return mid; 
    return binarySearch(a, l, r, target);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for( int i  = 0 ;i < n ; i++ )cin>>a[i];
    int target ;
    cin>> target;
    cout<<binarySearch(a, 0, n-1, target)<<endl;
}