#include<iostream>
#include<vector>

using namespace std;

int main(){
    double x;
    cin>>x;
    double l = 0.0, r = x ;
    while( ( r - l ) > 0.000001){
        long double mid = ( l + r )/2.0; 
        if( mid*mid > x) r = mid ;
        else l = mid;
    }
    cout<< r;
}