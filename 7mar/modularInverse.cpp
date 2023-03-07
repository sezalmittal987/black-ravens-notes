#include <iostream>
#include <utility>
using namespace std;

int gcd(int a, int b){
    if( b == 0 ) return a;
    return gcd(b, a%b);
}


//x0, y0
pair<int, int> extendedEuclidean(int a, int b){
    // base condition
    if( a == 0 ) return {0, 1};
    if( b == 0 ) return {1, 0};
    // relation
    pair<int, int> val = extendedEuclidean(b, a%b);
    int x0 = val.second;
    int y0 = val.first - (a/b)*val.second;
    return {x0, y0};
}

int main() {
    int b, m;
    cin>>b>>m;
    if( gcd(b, m ) != 1) {
        cout<<-1<<endl; 
        return 0;
    }
    pair<int, int> ans = extendedEuclidean(b, m);
    // if you have to make the number positive befor taking modulus
    if( ans.first < 0 ){ 
       int x =  (-ans.first) / m;
       ans.first += (x + 1)*m;
    }
    cout<<ans.first<<endl;
}