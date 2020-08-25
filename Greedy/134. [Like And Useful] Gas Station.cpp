// Strategy. O(N).
// A can not to B. so any C in A~B can not go to B.
// prove: if A can go C. left >= 0, but A can't go B. so C can't go B.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; ++i) gas[i] -= cost[i];
        int tot = accumulate(gas.begin(), gas.end(), 0);
        if(tot < 0) return -1;
        int tank = 0, res = 0;
        for(int i = 0; i < n; ++i){
            tank += gas[i];
            if(tank < 0){
                res = i+1;
                tank = 0;
            }
        }
        return res;
    }
};
