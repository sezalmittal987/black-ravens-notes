/*
https://leetcode.com/problems/global-and-local-inversions/description/
*/

class Solution {
public:
    bool isIdealPermutation(vector<int>& a) {
        int n = a.size();
        for( int i = 0 ; i < n ; i++ ){
            if( a[i] != i ){
                if( a[i] == i + 1 and a[i + 1] == i ){
                    swap(a[i], a[i+1]);
                }
                else return false;
            } 
        }
        return true;
    }
};