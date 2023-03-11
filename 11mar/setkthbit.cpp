#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    // n = n | int(pow(2, k));

    n = n | (1<<k);
    cout<<n<<endl;
}