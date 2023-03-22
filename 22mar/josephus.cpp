#include<iostream>
using namespace std;
int main(){
    int t, k;
    cin>>t>>k;
    for( int n = 1 ; n <= t ; n++){
        int a[n] = {}; // 0-> alive , 1 -> dead
        int dead = 0;
        int i = 0;
        while( dead < n - 1){
            int alive = 0 ;
            while( alive < k ){
                if( a[i] == 0 ) alive++;
                if( alive == k ) a[i] = 1;
                i = (i+1)%n;
            }
            dead++;
        }
        for( int i = 0 ; i < n ; i++){
            if( a[i] == 0 ) {
                cout<< n<<" "<<k<<" : "<< i  <<endl;
            }
        }
    }
}