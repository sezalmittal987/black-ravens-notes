#include<iostream>
#include<utility>

using namespace std;

int main(){
    // declare
    pair<int, int> a;
    // assign value
    pair<int, int> b = {1, 2};
    a = {1, 3};

    a = make_pair(1, 3);
    // accessing value
    cout<<a.first<<" " << a.second<<endl;
    cout<<b.first<<" " << b.second<<endl;

    a.first += 1;
    b.second *= 2;
    cout<<a.first<<" "<<b.second<<endl;
}