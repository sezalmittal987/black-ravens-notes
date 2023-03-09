#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n == 0 ){
        cout<<"0"<<endl;
        return 0;
    }
    string b;
    while( n > 0 ){
        b.push_back(n%2 + '0');
        n /= 2;
    }
    reverse(b.begin(), b.end());
    cout<<b<<endl;
}