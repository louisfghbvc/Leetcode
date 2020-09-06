// When repeat record the max cost.
// and always add relative min cost. mC = max Cost.

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int res = 0;
        int n = s.size();
        int mC = cost[0];
        for(int i = 1; i < n; ++i){
            if(s[i] == s[i-1]){
                if(cost[i] > mC){
                    res += mC;
                    mC = cost[i];
                }
                else{
                    res += cost[i];
                }
            }
            else{
                mC = cost[i];
            }
        }
        return res;
    }
};
