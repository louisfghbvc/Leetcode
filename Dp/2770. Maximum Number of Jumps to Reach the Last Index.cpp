class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        // goal: maximum jumps from index 0
        
        
        // jump to greater and abs(diff) <= target
        
        // idea: dp
        // dp[i]: starting index i maximum jump
        
        int n = nums.size();
        
        vector dp(n, -1);
        auto dfs = [&](auto &self, int i) -> int {
            if (i == n-1) return 0;
            
            int &res = dp[i];
            if (res != -1) return res;
            
            res = -1e5;
            for (int j = i+1; j < n; ++j) {
                if (abs(nums[j]-nums[i]) <= target)
                    res = max(res, 1+self(self, j));
            }
            
            return res;  
        };
        
        int ans = dfs(dfs, 0);
        return ans < 0 ? -1 : ans;
    }
};
