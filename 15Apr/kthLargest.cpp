/*
https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
*/

class KthLargest {
public:
    priority_queue<int, vector<int> , greater<int> > pqmin;
    int k;
    int curr = 0;
    KthLargest(int K, vector<int>& nums) {
        curr = 0;
        k = K;
        for( int i = 0 ;i < nums.size() ;i++){
            if(curr < k ){
                pqmin.push(nums[i]);
                curr++;
            }
            else{
                if( nums[i] > pqmin.top() ){
                    pqmin.push(nums[i]);
                    pqmin.pop();
                }
            }
        }
    }
    
    int add(int val) {
        if( curr < k or val > pqmin.top() ){
            pqmin.push(val);
            curr++;
            if( curr > k )pqmin.pop(), curr--;
        }
        return pqmin.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */