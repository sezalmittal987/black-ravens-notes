class Solution {
public:

    int binarySearch( vector<int>& a , int l, int r, int target){
        // base condition
        if(  l > r ) return -1;
        int mid = ( l + r)/2; 
        if( a[mid] > target ) r = mid -1 ;
        else if( a[mid] < target ) l = mid + 1;
        else return mid; 
        return binarySearch(a, l, r, target);
    }

    int search(vector<int>& a, int target) {
        int n = a.size();
        int l = 0, r = n-1;
        // binary search to find the pivot element.
        while(l<r){
            // find mid
            int mid = (l + r)/2;
            if( a[mid] >= a[0]) l = mid + 1;
            else r = mid;
        }
        int min_index = -1;
        if( a[l] >= a[0]) min_index = l+1;
        else min_index = l;
        // target falls on branch 1
        if( target >= a[0] ){
            int l = 0, r = min_index -1;
            return binarySearch(a, l, r, target);
        }
        // target falls on branch 2
        else{
            int l = min_index, r = n-1;
            return binarySearch(a, l, r, target);
        }
        return 0;
    }
};