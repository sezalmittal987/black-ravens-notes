/*
https://leetcode.com/problems/gas-station/description/
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = -1;
        int n = gas.size();
        int sp = -1;
        for( int i = 0 ; i < 2*n ; i++){
            if( sp == (i%n) and tank >= 0){
                return sp;
            }
            if( tank < 0 ){
                sp = i;
                tank = 0;
            }
            tank += gas[i%n] - cost[i%n];
        }
        return -1;
    }
};