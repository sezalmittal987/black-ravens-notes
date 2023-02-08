class Solution {
public:
    int characterReplacement(string a, int k) {
        int n = a.length();
        int ans = 0;
        for( char c = 'A' ; c <= 'Z' ; c++){
            int i =  0, j = 0, t = 0; 
            
            // t -> current no. of flipped bits
            // counting max consec As
            while( i < n  and j < n ){
                if( a[j] != c ){
                    if( t < k ){
                        t++;
                        j++;
                    }
                    else if( t == k){
                        if( a[i] != c ) t--;
                        i++;
                    }
                }
                else{
                    j++;
                } 
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};