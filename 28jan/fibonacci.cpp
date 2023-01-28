#include<iostream>
#include<vector>
using namespace std;

// int fib(int i){
//     //base conditions
//     if( i == 1) return 1;
//     if ( i == 2) return 1;
//     //code
//     return fib(i-1) + fib(i-2);
// }

int fibonacci( int n, vector<int>& f ){
    if( n == 1) return 1;
    if( n == 2 ) return 1;
    if( f[n] != 0 ) return f[n];
    int sum = fibonacci( n-1, f )+ fibonacci( n - 2, f);
    f[n] = sum;
    cout<<sum<<" ";
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<int> f(n + 1, 0);
    f[1] = 1;
    f[2] = 1;
    /* Solution 1
    cout<<fib(n)<<endl;
    for( int i = 1 ; i <= n ; i++ ){
        cout<<fib(i)<<" ";
    }
    */
   cout<< f[1] <<" "<<f[2]<<" ";
   fibonacci(n, f);
    cout<<endl;

    /* Solution 3
    for( int i = 1 ;i <= n ; i++ ){
        cout<<f[i]<<" ";
    }
    cout<<endl;
    */
}