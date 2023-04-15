#include<bits/stdc++.h>

using namespace std;


bool compare( int a, int b) {
    // return a < b ; // max heap
    return a > b; // min heap 
}

void printHeap( vector<int> & a){
     for( int i= 0 ; i < a.size() ; i++ ){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void heapify(vector<int>& a, int i){
    int n = a.size();
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i ;// maximum node of three( parent, left, right)
    if( l < n and compare(a[largest], a[l]) ) largest = l;
    if( r < n and compare(a[largest], a[r])) largest = r;
    swap(a[i], a[largest]);
    if( largest != i ) heapify( a, largest);
}

void popNode(vector<int> &a){
    //swap with the last node
    swap(a[0], a[a.size() -1 ]);
    // remove the last node
    a.pop_back();
    heapify(a, 0);
    printHeap(a);

}

void insertNode( vector<int>& a, int x){
    // insert at the end
    a.push_back(x);
    int curr = a.size() -1 ;
    while( curr > 0 ){
        int parent = (curr - 1)/2;
        if( compare(a[parent] , a[curr]) ) swap(a[parent] , a[curr]);
        curr = parent; 
    }
    printHeap(a);
}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for( int i= 0 ; i < n ; i++ ){
        cin>>a[i];
    }
    for( int i = n-1 ; i >= 0 ; i-- ){
        heapify( a, i);
    }
    printHeap(a);
    insertNode(a, 11);
    popNode(a);
}