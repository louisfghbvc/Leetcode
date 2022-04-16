class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        // goal: buy any not zero 
        // idea: dp[i] number of ways that buy i dollars
        // note the order doesn't matter
        
        vector<long> dp(total+1);
        dp[0] = 1;
        
        for (int i = 1; i <= total; ++i) {
            if (i >= cost1)
                dp[i] += dp[i-cost1];
        }
        for (int i = 1; i <= total; ++i) {
            if (i >= cost2)
                dp[i] += dp[i-cost2];
        }
        
        return accumulate(dp.begin(), dp.end(), 0L);
    }
};
