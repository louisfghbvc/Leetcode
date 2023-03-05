// Way1, Bottom up

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        // goal: find the number of ways to reach target
        // idea: flatten the types
        // dp
        // dp[i]: nubmer of ways reach target
        // dp[i] = dp[i-score]
        
        int mod = 1e9+7;
        int n = types.size();
        vector<long> dp(target+1, 0);
        dp[0] = 1; // base case
        
        for (auto &v: types) {
            auto next_dp = dp;
            int score = v[1];
            for (int j = 0; j < v[0]; ++j) {
                for (int i = score; i <= target; ++i) {
                    next_dp[i] = (dp[i-score] + next_dp[i]) % mod;
                }
                score += v[1];
            }
            swap(dp, next_dp);
        }
        
        return dp[target];
    }
};

// Way2 - Top down

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        // goal: find the number of ways to reach target
        // idea: flatten the types
        // dp
        // dp[i]: nubmer of ways reach target
        
        // dp[i] = dp[i-score]
        
        int mod = 1e9+7;
        int n = types.size();
        vector dp(n, vector<long>(target+1, -1));
        auto dfs = [&](auto &self, int i, int cur) -> long {
            if (cur >= target) return cur == target;
            if (i >= n) return 0;
            
            long &res = dp[i][cur];
            if (res != -1) return res;
            
            res = self(self, i+1, cur); // skip type i
            
            // used i
            for (int j = 0; j < types[i][0]; ++j) {
                cur += types[i][1];
                res += self(self, i+1, cur);
                res %= mod;
            }
            return res;
        };
        
        return dfs(dfs, 0, 0);
    }
};
