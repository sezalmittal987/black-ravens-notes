#include<iostream>
#include<vector>

using namespace std;

void quickSort(vector<int>& a, int s, int e){

    // base condition
    if( s >= e) {
        return;
    }
    // pivot element
    // pivot position
    int p = s + 1, q = e;
    while(true){
        while( p < e and  a[p] <= a[s]){
            p++;
        }
        while( a[q] > a[s] ) {
            q--;
        }
        if( p < q ) swap(a[p], a[q]);
        else{
            swap(a[s], a[q]);
            break;
        }
    }
    // partition
    // s -> q-1
    // q + 1 -> e
    quickSort(a, s, q-1);
    quickSort(a, q+1, e);

}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for( int i  =0 ;i < n ; i++ ) cin>>a[i];
    quickSort(a, 0, n-1);
    for( int i  =0 ;i < n ; i++ ) cout<<a[i]<<" "; cout<<endl;
}