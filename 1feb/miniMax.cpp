#include<iostream>
#include<vector>
using namespace std;

int minMaxGame(vector<int>& a) {
    if ( a.size() == 1) return a[0];
    vector<int> v;
    int n = a.size();
    for ( int i  = 0 ; i < n ; i+= 4) {
        v.push_back(min(a[i], a[i +1]));
        if ( a.size() > 2 ) v.push_back(max(a[i+ 2], a[i+ 3]));
    }
    return minMaxGame(v);
}

int main(){
    
}