class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        // goal: number of ways reach endPos use k steps
        // idea: dp
        // dp[x][number of step we use] 
        
        int dp[k+1][3000];
        memset(dp, -1, sizeof dp);
        
        int mod = 1e9+7;
        
        auto dfs = [&](const auto &self, int x, int used) -> int {
            if (used == k) return x-1000 == endPos; // base case
            
            int &res = dp[used][x];
            if (res != -1) return res;
            
            // right, left
            res = (self(self, x+1, used+1) + self(self, x-1, used+1)) % mod;
            return res;
        };
        
        return dfs(dfs, startPos+1000, 0);
    }
};

// Use math
