class Solution {
public:
    int countWinningSequences(string s) {
        // goal: count the winning sequence of bob
        // idea:
        // F>E
        // W>F
        // E>W
        
        // dp[i][x]: number of way such that starting from index i, x is the diff of rewards
        // each index
        // we can win/draw/lose
        
        unordered_map<char, int> mp = {{'F', 0}, {'W', 1}, {'E', 2}};
        
        int mod = 1e9+7;
        
        int n = s.size();
        vector dp(n, vector(2*n+1, vector<long>(4, -1)));
        
        auto dfs = [&](auto &self, int i, int x, int prev) -> long {
            if (i >= n) return x > 0;
            
            auto& res = dp[i][x+n][prev];
            if (res != -1) return res;
            
            res = 0;
            // draw
            if (mp[s[i]] != prev) {
                res = self(self, i+1, x, mp[s[i]]);
            }
            // win
            if ((mp[s[i]]+1)%3 != prev) {
                res = (res + self(self, i+1, x+1, (mp[s[i]]+1)%3)) % mod;
            }
            // lose
            if ((mp[s[i]]+2)%3 != prev) {
                res = (res + self(self, i+1, x-1, (mp[s[i]]+2)%3)) % mod;
            }
            
            return res;
        };
        
        return dfs(dfs, 0, 0, 3);
    }
};
