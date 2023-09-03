class Solution {
public:
    int minimumOperations(string num) {
        // goal: find the minimum operations to make num divisible by 25
        
        // 1 <= num <= 100
        // nums[i] is 0-9
        
        // idea: dp
        // skip
        // dp(i, cur) -> dp(i+1, cur)
        // used
        // dp(i, cur) -> dp(i+1, cur*10 + d)
            
        int n = num.size();
        vector dp(n+1, vector(26, -1));
        auto dfs = [&](auto &self, int i, int cur) -> int {
            if (i >= n) return cur == 0 ? 0 : 1e9;
            
            int &res = dp[i][cur];
            if (res != -1) return res;
            
            res = 1 + self(self, i+1, cur);
            res = min(self(self, i+1, (cur*10+num[i]-'0')%25), res);
            return res;
        };
        
        return dfs(dfs, 0, 0);
    }
};
