class Solution {
public:
    int specialPerm(vector<int>& nums) {
        // goal: find the all permuation that is special
        // idea:
        // brute force -> TLE
        // for each postition we can choose a num
        // dp[i][mask]: starting from index i, current we have already choose
        
        int n = nums.size();
        
        vector dp(n+1, vector(1<<n, -1));
        int mod = 1e9+7;
        
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i)
            mp[nums[i]] = i;
        
        auto dfs = [&](auto &self, int prev, int mask) {
            if (__builtin_popcount(mask) == n) return 1;
            
            int &res = dp[prev][mask];
            if (res != -1) return res;
            
            res = 0;
            for (int j = 0; j < n; ++j) {
                if (mask >> j & 1) continue;
                if (prev == n || nums[j] % nums[prev] == 0 || nums[prev] % nums[j] == 0)
                    res = (res + self(self, j, mask | (1<<j))) % mod;
            }
            return res;
        };
        
        return dfs(dfs, n, 0);
    }
};
