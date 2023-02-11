class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        vector<int> c;
        int i = 0, j = 0;
        //run while both pointers are in range
        while(i < m and j < n){
            if( a[i] <= b[j]){
                c.push_back(a[i]);
                i++;
            }
            else{
                c.push_back(b[j]);
                j++;
            }
        }
        // atleast one pointer is out of range
        while( j < n ){     // if pointer i is out of range
            c.push_back(b[j]);
            j++;
        } 
        while(i < m){       // if pointer j is out of range
            c.push_back(a[i]);
            i++;
        }
        for( int i = 0 ; i < m + n ; i++ ){
            a[i] = c[i];
        }
    }
};