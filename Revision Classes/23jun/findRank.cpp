typedef long long ll;

int mod = 1000003;

// to calculate x^y
ll power(ll x, ll y ){
    ll res = 1;
    x = x % mod;
    if(x == 0 ) return x;
    while (y > 0){
        if (y & 1) res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}

// to calculate mod modInverse
ll modInverse(ll n ){
    return power(n, mod-2);
}

int Solution::findRank(string s) {
    int n = s.length();
    // precalculate factorial values
    int fac[n+1];
    fac[0] = 1;
    for ( int i=1 ; i<= n; i++) fac[i] = (fac[i-1]*i)%mod;
    // count all occurences
    unordered_map<char, int> cnt;
    for( int i = 0 ; i < n ; i++ ) cnt[s[i]]++;
    
    int ans = 1;
    for( int i = 0  ; i < n ;i++){
        // count previous permutation
        ll prevPer = 0; 
        
        // precalculation of (remaining letters!)/cnt1!*cnt2!*cnt3!....
        int rem = 0;
        ll prec = 1;
        for( auto u : cnt){
            rem += u.second;
            if( u.second > 1 ) prec *= modInverse(fac[u.second]);
            prec %= mod;
        }
        rem -=1;
        prec *= fac[rem];
        prec %= mod;
        
        // for smaller letters, add previous permutations
        for( auto u : cnt){
            if( u.first >= s[i]) continue;
            if( u.second > 0 ){
                // ex : prec = 7!/(4!*3!) 
                // prec*(taking character u.first as starting letter)
                // 7!/(4!*3!) * (4!/3!) --> 7!/(4!*3!) * 4
                prevPer += (prec*u.second)%mod; 
                prevPer %= mod;
            }
        }
        ans += prevPer;
        ans %= mod;
        // fix current character
        cnt[s[i]]--;
    }
    return ans;
}