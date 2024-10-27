class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        // goal: find the number of pair count, such that gcd is same
        
        // idea:
        // [1, 2, 3, 4] => 
        
        // consider dp
        
        int n = nums.size();
        int mod = 1e9+7;
        vector dp(n, vector(205, vector(205, -1)));
        
        auto dfs = [&](auto &self, int i, int x, int y) -> int {
            if (i == n) return x == y;
            
            int& res = dp[i][x][y];
            if (res != -1) return res;
            
            res = self(self, i+1, x, y);
            res = (res + self(self, i+1, __gcd(nums[i],x), y)) % mod;
            res = (res + self(self, i+1, x, __gcd(nums[i],y))) % mod;
            return res;
        };
        
        return dfs(dfs, 0, 0, 0) - 1;
    }
};
