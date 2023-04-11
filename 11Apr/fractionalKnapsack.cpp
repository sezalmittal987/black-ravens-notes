/*
https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
*/


/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    static bool compare( Item a, Item b){
        if( double(a.value)/double(a.weight) >  double(b.value)/double(b.weight)) return true;
        return false;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // array is sorted based on decreasing quality
        sort(arr, arr+n , compare);
        double ans = 0;
        double rem = W;
        for( int i = 0 ;i < n ; i++ ){
            if( rem < arr[i].weight) {
                ans += (rem)*((double)arr[i].value/(double)arr[i].weight);
                rem = 0;
            }
            else{
                ans += arr[i].value;
                rem -= arr[i].weight;
            }
        }
        return ans;
    }
        
};