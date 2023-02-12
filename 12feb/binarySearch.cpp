#include<iostream>
#include<vector>

using namespace std;


// To return the last index of the target
int binarySearch2( int *a , int l, int r, int target){
    // base condition
    if( l == r ){
        if( a[l] == target ) return l;
        else return -1;
    } 
    int mid = ( l + r +1)/2; 
    if( a[mid] > target ) r = mid -1 ;
    else l = mid; 
    return binarySearch2(a, l, r, target);
}

// To return the first index of the target
int binarySearch3( int* a, int l, int r, int target){
    // base condition
    if( l == r ){
        if( a[l] == target ) return l;
        else return -1;
    } 
    int mid = ( l + r)/2; 
    if( a[mid] < target ) l = mid + 1;
    else r = mid;
    return binarySearch3(a, l, r, target);
}

// Tip : 1. check which is the case ( first or last), 2. check conditions on l or r, 3. write mid accordingly
int binarySearch( int *a , int l, int r, int target){
    // base condition
    if(  l > r ) return -1;
    int mid = ( l + r)/2; 
    if( a[mid] > target ) r = mid -1 ;
    else if( a[mid] < target ) l = mid + 1;
    else return mid; 
    return binarySearch(a, l, r, target);
}

int binarySearchIterative2(int *a, int l, int r, int target){
    while( l < r ){
        int mid = ( l + r + 1)/2;
        if( a[mid]  > target ) r = mid - 1;
        else l = mid;
    }
    if( a[l] == target)  return l;
    return -1;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for( int i  = 0 ;i < n ; i++ )cin>>a[i];
    int target ;
    cin>> target;
    cout<<binarySearch3(a, 0, n-1, target)<<endl;
    // Iterative solution for binarySearch2 
}