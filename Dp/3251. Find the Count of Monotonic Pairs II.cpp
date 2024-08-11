class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        // goal: find out the number of pairs such that
        // arr1 is increase, arr2 is decreasing
        
        // idea:
        // dp
        
        // dfs(i, x): starting from index i, the last number of arr1 is x, arr2 is nums[i]-x;
        // TC: O(n*x*x)
        
        // how to improve?
        // dp[i][last] = dp[i+1][x], if x >= last && nums[i] - x <= nums[i-1] - last, x - last >= 0, nums[i] - nums[i-1] <= x - last, x - last >= max(0, nums[i] - nums[i-1])
        
        // dp[i][x] = sum of (dp[i-1][y]), y = 0 ~ x-(nums[i]-nums[i-1])
        // x - (nums[i]-nums[i-1]) >= last
        
        // if (x >= last && nums[i] - x <= nums[i-1] - last)
        // last <= x
        // last <= x + nums[i-1] - nums[i]
        // 
        
        
        // make transition to O(1)
        
        int n = nums.size();
        int mod = 1e9+7;
        
        int MX = 2e3+5;
        
        vector dp(n, vector(MX, 0));
        for (int x = 0; x <= nums[0]; ++x)
            dp[0][x] = 1;
        
        for (int i = 1; i < n; ++i) {
            vector<long> pre(MX);
            pre[0] = dp[i-1][0];
            for (int x = 1; x < MX; ++x)
                pre[x] = (dp[i-1][x] + pre[x-1]) % mod;
            
            for (int x = 0; x <= nums[i]; ++x) {
                int bound = x + min(nums[i-1] - nums[i], 0);
                if (bound >= 0)
                    dp[i][x] = pre[bound]; 
            }
        }
        
        long res = 0;
        for (int x = 0; x < MX; ++x)
            res = (res + dp[n-1][x]) % mod;
        return res;
    }
};
