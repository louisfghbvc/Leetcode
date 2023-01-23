// top-down Dp !

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        // importance value = k+trimm length
        // goal: find the minimum cost 
        // n = nums.size()
        // nums[i] <= n
        
        // [1,2,1,2,1], k=5
        //  1,
        // idea: dp, each index can split subarray
        
        int n = nums.size();
        
        vector<int> dp(n, -1);
        
        auto dfs = [&](auto &self, int i) {
            if (i >= n) return 0; // base case;
            
            int &res = dp[i];
            if (res != -1) return res;
            
            res = INT_MAX;
            vector<int> cnt(n);
            int sum = 0;
            for (int j = i; j < n; ++j) {
                ++cnt[nums[j]];
                if (cnt[nums[j]] == 2) sum += 2;
                else if (cnt[nums[j]] > 2) sum++;
                // split
                res = min(res, k + sum + self(self, j+1));
            }
            return res;
        };
        
        return dfs(dfs, 0);
    }
};
