#include <iostream>
#include <utility>
using namespace std;

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
    int a, b;
    cin>>a>>b;
    pair<int, int> ans = extendedEuclidean(a, b);
    cout<<ans.first<<" "<<ans.second<<endl;
}