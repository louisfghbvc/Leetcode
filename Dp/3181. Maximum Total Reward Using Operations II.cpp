class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        // goal: find the maximum rewardValues
        // idea: order is no matter
        // we can sort the array
        // each position we can add value or not
        // dp[i][x]: maximum so far in the index i, current value x
        
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
                
        bitset<50000> dp;
        dp[0] = 1;
        for (int x: rewardValues) {
            dp |= (dp<<(50000-x)>>(50000-x)) << x;
        }
        
        set<int> poss; // possible sum
        for (int j = 0; j <= 50000; ++j)
            if (dp[j])
                poss.insert(j);
        
        int res = 0;
        for (int x: rewardValues) {
            auto it = prev(poss.lower_bound(x));
            res = max(res, x + *it);
        }
        
        return res;
    }
};
