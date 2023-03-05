class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        // goal: split range into two groups
        // overlapping must be the same group
        
        // idea:
        // sort the range
        // dp[i][0]: number of ways where i put in first group
        
        sort(ranges.begin(), ranges.end());
        
        int n = ranges.size();
        int mod = 1e9+7;
        vector dp(n, vector<long>(2, -1));
        
        auto dfs = [&](auto &self, int i, int last, int type) -> long {
            if (i == n) return 1;
            long &res = dp[i][type];
            if (res != -1) return res;
            
            res = 0;
            if (ranges[i][0] <= last) // must put same
                res = self(self, i+1, max(last, ranges[i][1]), type);
            else {
                res = self(self, i+1, max(last, ranges[i][1]), 0);
                res += self(self, i+1, max(last, ranges[i][1]), 1);
                res %= mod;
            }
                
            return res;
        };
        
        return dfs(dfs, 0, -1, 0) % mod;
    }
};
