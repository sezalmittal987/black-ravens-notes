#include<iostream>
using namespace std;

pair<int, int> extendedGCD(int a, int b){
    if( a == 0 ) return {0, 1};
    if( b == 0 ) return {1, 0};
    pair<int, int> prev = extendedGCD(b%a , a);
    int x = - prev.first*(b/a) + prev.second;
    int y = prev.first;
    return {x, y};
}

int main(){
    int a = 8, b = 10;
    pair<int, int> values = extendedGCD(a, b);
    cout<<values.first<<" "<<values.second<<endl;
}