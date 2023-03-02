#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> ans;
    for( int i = 2 ; i*i <= n ; i++ ){
        // if(isPrime(i)){ // is not needed
            int p = 0 ;
            // always fail for composite numbers 
            // because composite numbers are products of prime numbers
            // and we are removing (smaller) prime numbers from n,
            // which means the composite number will never be a factor
            while(n%i == 0 ){    
                n/=i;
                p++;
            }
            if( p > 0 ) ans.push_back({i, p});
        // }
    }
    if( n > 1 ) ans.push_back({n, 1});
    for( int i = 0  ; i < ans.size() ;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}