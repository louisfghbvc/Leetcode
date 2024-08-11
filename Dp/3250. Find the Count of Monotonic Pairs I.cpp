class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        // goal: find out the number of pairs such that
        // arr1 is increase, arr2 is decreasing
        
        // idea:
        // dp
        
        // dfs(i, x): starting from index i, the last number of arr1 is x, arr2 is nums[i]-x;
        
        int n = nums.size();
        int mod = 1e9+7;
        
        vector dp(n, vector(55, -1));
        auto dfs = [&](auto &self, int i, int last) -> int {
            if (i >= n) return 1;
            
            int& res = dp[i][last];
            if (res != -1) return res;
            
            res = 0;
            for (int x = 0; x <= nums[i]; ++x) {
                if (x >= last && nums[i] - x <= nums[i-1] - last)
                res = (res + self(self, i+1, x)) % mod;
            }
            return res;
        };
        
        long res = 0;
        for (int x = 0; x <= nums[0]; ++x)
            res = (res + dfs(dfs, 1, x)) % mod;
        
        return res;
    }
};
