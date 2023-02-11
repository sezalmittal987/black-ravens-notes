#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int> & a, int si, int ei, int sj, int ej){
    vector<int> c;
    int i = si, j = sj;
    while( i<= ei and j <= ej){
        if( a[i] <= a[j]){
            c.push_back(a[i]);
            i++;
        }
        else{
            c.push_back(a[j]);
            j++;
        }
    }
    while(i <=ei ) {
        c.push_back(a[i]);
        i++;
    }
    while( j <= ej ){
        c.push_back(a[j]);
        j++;
    }
    // copy vector c into vector a 
    for( int i = si ;i <= ej ;i++ ){
        a[i] = c[i-si]; 
    }
}

// s -> starting index of array
// e -> ending index of array
void mergeSort(vector<int>& a, int s, int e ){
    //base condition 
    if( s >= e){ // only one element in the array.
        return;
    }
    // divide into part
    int ei = (e + s)/2;
    int sj = ei + 1;
    int si = s;
    int ej = e;
    // call function for both parts
    mergeSort(a, si, ei);
    mergeSort(a, sj, ej);
    
    // merge two parts

    merge(a, si, ei, sj, ej);
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i =0 ;i < n ; i++ )cin>>a[i];
    mergeSort(a, 0, n-1);
    for(int i =0 ;i < n ; i++ ) cout<<a[i]<<" "; cout<<endl;
}