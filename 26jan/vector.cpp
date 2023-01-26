#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a;
    cout<<a.size()<<endl; // tells size of vector
    a.push_back(1); // to add elements to the vector
    cout<<a.size()<<endl;
    cout<<a[0]<<endl;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    cout<<a.size()<<endl; // 5
    for( int i = 0 ;i < 5 ; i++ ){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}