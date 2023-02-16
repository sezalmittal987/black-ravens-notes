#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main() {
    pair<string, char> p;
    cin>>p.first>>p.second;
    p.first.push_back(p.second);
    cout<<p.first<<' '<<p.second<<endl;
    
    return 0;
}